#!/bin/env bash
project_dir=~/dev/rice-light
dependencies=../lib/dependencies.txt
cd $project_dir/lib
while read dep; do
  git clone $dep
done < $project_dir/lib/dependencies.txt
