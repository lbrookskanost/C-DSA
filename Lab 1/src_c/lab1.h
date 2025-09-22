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

/*
 * Does in-place insertion sort on an array of ints.
 * Returns a new sorted array.
 */
int* insertion_inplace(int* arr, int length);

/*
 * Does insertion sort on an array of ints.
 * Allocate and returns a new sorted array.
 * Caller is responsible for freeing the returned ptr.
 */
int* insertion(int* arr, int length);

/* 
 * Helper function for insertion().
 * Inserts an item at an index to an array.
 */
void insert(int* arr, int index, int item);

#endif // LAB1_H
