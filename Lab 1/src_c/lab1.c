#include <stdio.h>
#include <stdlib.h>
#define INT_SIZE sizeof(int)

int* merge_sort(int* arr, int length);
int* merge(int* a, int* b, int a_len, int b_len);
//TODO: Create insertion sort functions

int* merge_sort(int* arr, int length){
    if (length == 1) {
        int* single = (int*)malloc(INT_SIZE);
        single[0] = arr[0];
        return single;
    }
    
    int middle = length/2;
    
    int* arr_left = (int*)malloc((middle)*INT_SIZE);  

    for(int i = 0; i < middle; i++)
        arr_left[i] = arr[i];
        
    int * arr_right = (int*)malloc((length-middle)*INT_SIZE); 

    for(int i = middle; i < length; i++)
        arr_right[i - middle] = arr[i];
        
    int* left = merge_sort(arr_left, middle);
    int* right = merge_sort(arr_right, length-middle);
    free(arr_left); free(arr_right);
    int* result = merge(left, right, middle, length - middle);
    free(left); free(right);
    return result;
}

int* merge(int* a, int* b, int a_len, int b_len){
    int c_len = 0;
    int* c = (int*)malloc((a_len + b_len) * INT_SIZE);
    int i = 0; int j = 0;
    while ((i < a_len) && (j < b_len)){
        if (a[i] < b[j]){
            c[c_len] = a[i];
            i++; 
        } else {
            c[c_len] = b[j];
            j++;
        }
        c_len++;
    }
    while (i < a_len){
        c[c_len] = a[i];
        c_len++; i++;
    }
    while (j < b_len){
        c[c_len] = b[j];
        c_len++; j++;
    }
    return c;
}