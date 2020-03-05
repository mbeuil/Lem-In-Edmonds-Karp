#!/bin/bash

set -o errexit

trap 'if [[ $? -eq 139 ]]; then echo "SEGFAULT"; fi' EXIT

function pause ()
{
  read -n 1 -rs
}

function test ()
{
  echo "Begin Testing Generator: $1"
  echo ""

  INDEX=0
  SUM_MINE=0
  SUM_GENERATOR=0
  while [ $INDEX -lt 30 ]; do
    INDEX=$((INDEX + 1))
    progress $((INDEX * 100 / 30)) "Processing..."
    RESULT="$(./scripts/generator $1 | ./lem-in)"
    GENERATOR="$(echo "$RESULT" | sed -n '2p' | cut -d ':' -f 2)"
    SUM_GENERATOR=$((SUM_GENERATOR + GENERATOR))
    MINE="$(echo "$RESULT" | awk '/^$/,p' | grep -ve '^$' -c)"
    SUM_MINE=$((SUM_MINE + MINE))
  done

  AVG_GENERATOR=$(($SUM_GENERATOR / 30))
  AVG_MINE=$(($SUM_MINE / 30))
  echo "Average Generator: $AVG_GENERATOR"
  echo "Your Average: $AVG_MINE"
  echo ""
  pause
}

function perf ()
{
  source ./scripts/progress.sh

  echo -n "Use generator? [y/n]: "
  read -n 1 ANSWER
  echo ""
  echo ""

  if [[ $ANSWER == "y" ]]; then
    test --flow-one
    test --flow-ten
    test --flow-thousand
    test --big
    test --big-superposition
  fi
}

perf
