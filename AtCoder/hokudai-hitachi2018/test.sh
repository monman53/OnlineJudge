#!/bin/bash

make

#for i in {1..3}; do
for i in {3..3}; do
#for i in {1..1}; do
    echo "#================"
    echo "# "$i
    echo "#================"
    sum=0
    for j in {0..100}; do
        tmp_in=$(mktemp)
        tmp_out=$(mktemp)
        toolkit/scripts/generator.out $tmp_in $i $j
        ./$i.out < $tmp_in > $tmp_out
        #toolkit/scripts/output_checker.out $tmp_in $tmp_out 0
        ans=$(toolkit/scripts/output_checker.out $tmp_in $tmp_out 0)
        #echo $ans
        sum=$((sum+ans))
        rm $tmp_in $tmp_out
    done
    echo $sum
done
