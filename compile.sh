#!/bin/bash
gcc -c file_aux.c
gcc exec.c -o exec.o file_aux.o
gcc mergesort.c -o mergesort.o file_aux.o
gcc insertionsort.c -o insertionsort.o file_aux.o
g++ heapsort.cpp -o heapsort file_aux.o -w