#include <stdio.h>
#include <stdlib.h>
#define INT_SIZE sizeof(int)

int* merge_sort(int* arr, int length);
int* merge(int* a, int* b, int a_len, int b_len);
int* insertion_inplace(int* arr, int length);
int* insertion(int* arr, int length);
void insert(int* arr, int index, int item);

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

int* insertion_inplace(int* arr, int length){
    for (int i = 1; i < length; i++){
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return arr;
}

int* insertion(int* arr, int length){
    int* arr2 = (int*)malloc(length * INT_SIZE);
    arr2[0] = arr[0];
    int arr2_len = 1;
    for (int i = 1; i < length; i++){
        int inserted = 0;
        for (int j = 0; j < arr2_len; j++){
            if (arr[i] < arr2[j]){ //insert j at a[i]
                insert(arr2, j, arr[i]);
                inserted = 1; arr2_len++;
                break;
            } 
        }
        if (!inserted) {
            insert(arr2, arr2_len, arr[i]);
            arr2_len++;
        }
    }
    return arr2;
}

void insert(int *arr, int index, int item){
	/* To do- finish */
    return;
}