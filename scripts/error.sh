#!/bin/bash

function check ()
{
  command -v valgrind >/dev/null 2>&1 || echo "not_installed"
}

function pause ()
{
  read -n 1 -rs
}

function timeout ()
{
  START=0
  PID=`ps | grep "lem-in" | grep -v "grep" | awk '{ print $1 }'`
  while kill -0 $PID; do
    read -t 1
    START=$((START+1))
    if [ $START -ge 10 ]; then
      kill $PID && echo "Timeout" && break
    fi
  done
}

function invalid ()
{
  echo "Begin Testing Unvalid Maps"
  echo ""

  FILES=`find -s maps/invalid/ -type f`

  for FILE in $FILES; do
    TITLE=`head -n 1 $FILE`
    if [[ -z $TITLE ]]; then
      echo "#empty file"
    elif [[ -n $TITLE ]]; then
      echo $TITLE
    fi
    if [[ $1 == "y" ]]; then
      valgrind ./lem-in < $FILE
    else
      ./lem-in < $FILE
    fi
    echo ""
    pause
  done

  echo "#/dev/null"
  if [[ $1 == "y" ]]; then
    valgrind ./lem-in < /dev/null
  else
    ./lem-in < /dev/null
  fi
  echo ""
  pause

  echo "#/dev/zero"
  if [[ $1 == "y" ]]; then
    RESULT=`valgrind ./lem-in < /dev/zero & timeout`
  else
    RESULT=`./lem-in < /dev/zero & timeout`
  fi
  echo $RESULT
  echo ""
  pause

  echo "#/dev/random"
  if [[ $1 == "y" ]]; then
    RESULT=`valgrind ./lem-in < /dev/random & timeout`
  else
    RESULT=`./lem-in < /dev/random & timeout`
  fi
  echo $RESULT
  echo ""
}

function main ()
{
  echo -n "Use valgrind? [y/n]: "
  read -n 1 ANSWER
  echo ""
  echo ""

  if [[ $ANSWER == "y" ]]; then
    VALGRIND=$(check)
    if [[ -z $VALGRIND ]]; then
      VALGRIND=$ANSWER
    elif [[ $VALGRIND == "not_installed" ]]; then
      VALGRIND="n"
      echo "I require valgrind but it's not installed"
      echo "Continuing without it"
      echo ""
    fi
  else
    VALGRIND=$ANSWER
  fi

  invalid $VALGRIND
}

main
