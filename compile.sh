#!/bin/bash
gcc -c file_aux.c
gcc exec.c -o exec.o file_aux.o
gcc mergesort.c -o mergesort.o file_aux.o