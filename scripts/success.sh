#!/bin/bash

function check ()
{
  command -v valgrind >/dev/null 2>&1 || echo "not_installed"
}

function pause ()
{
  read -n 1 -rs
}

function valid ()
{
  echo "Begin Testing Simple Valid Maps"
  echo ""

  FILES=`find -s maps/valid/ -type f`

  for FILE in $FILES; do
    echo $FILE
    if [[ $1 == "y" ]]; then
      valgrind ./lem-in < $FILE
    else
      ./lem-in < $FILE
    fi
    echo ""
    pause
  done
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

  valid $VALGRIND

  source ./scripts/perf.sh
}

main
