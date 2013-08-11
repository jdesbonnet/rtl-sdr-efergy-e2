#!/bin/bash
C_FILES="e2-decode  hpf  raw-to-numbers  zc-freq"

for f in $C_FILES; do
	gcc -o $f $f.c
done

