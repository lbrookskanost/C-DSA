#ifndef LAB1_H
#define LAB1_H

#include <stdio.h>
#include <stdlib.h>

#define INT_SIZE sizeof(int)

/*
 * Performs merge sort on an array of integers.
 * Allocates and returns a new sorted array.
 * Caller is responsible for freeing the returned pointer.
 */
int* merge_sort(int* arr, int length);

/*
 * Merges two sorted arrays into a single sorted array.
 * Allocates and returns a new merged array.
 * Caller is responsible for freeing the returned pointer.
 * 
 */
int* merge(int* a, int* b, int a_len, int b_len);

#endif // LAB1_H
