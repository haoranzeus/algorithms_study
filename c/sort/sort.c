#include <stdlib.h>
#include <malloc.h>
#include "sort.h"

// ================================================================
// insertion sort
// ================================================================
void insertion_sort(int * array, int size){
    int key, i;
    for (int j = 1; j < size; j++) {
        key = array[j];
        i = j - 1;
        while ( i >= 0 && array[i] > key) {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = key;
    }
}

// ================================================================
// merge sort
// ================================================================

void merge(int * array, int head, int middle, int tail){
    int n1 = middle - head + 1;
    int n2 = tail - middle;
    int * L = malloc(n1 * sizeof(int));
    int * R = malloc(n2 * sizeof(int));
    int i = 0, j = 0;
    for ( i = 0; i < n1; ++i) {
        L[i] = array[head + i];
    }
    
    for ( j = 0; j < n2; ++j) {
        R[j] = array[middle + 1 + j];
    }
    i = 0;
    j = 0;
    for ( int k = head; k < tail + 1; k++) {
        if ( i == n1 ) {
            array[k] = R[j++];
        }
        else if ( j == n2 ) {
            array[k] = L[i++];
        }
        else if ( L[i] <= R[j]) {
            array[k] = L[i++];
        }
        else if ( L[i] > R[j] ) {
            array[k] = R[j++];
        }
    }
    free(L);
    free(R);
}

void merge_sort(int *array, int head, int tail){
    if ( head < tail ) {
        int middle = (head + tail) / 2;
        merge_sort(array, head, middle);
        merge_sort(array, middle + 1, tail);
        merge(array, head, middle, tail);
    }
}

// ================================================================
// bubble sort
// ================================================================
void bubble_sort(int *array, int size){
    int tmp;
    for ( int i = 0; i < size; i++ ) {
        for ( int j = size - 1; j > i; --j ) {
            if ( array[j] < array[j-1] ) {
                tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
            }
        }
    }
}


// ================================================================
// heap sort
// ================================================================
#define LEFT(i)     (2 * i)
#define RIGHT(i)    (2 * i + 1)
void max_heapify(int * array, int node, int array_size){
    int heap_size = array_size;
    int l = LEFT(node);
    int r = RIGHT(node);
    int largest;
    if (l <= heap_size && array[l] > array[node]) {
        largest = l;
    }
    else {
        largest = node;
    }
    if (r <= heap_size && array[r] > array[largest]) {
        largest = r;
    }
    if (largest != node) {
        int tmp = array[node];
        array[node] = array[largest];
        array[largest] = tmp;
    }
    if (largest != node)
        max_heapify(array, largest, array_size);
}

void build_max_heap(int * array, int array_size){
    for (int i = array_size/2; i >= 1; i--) {
        max_heapify(array, i, array_size);
    }
}

void heap_sort(int * array, int array_size){
    build_max_heap(array, array_size);
    int heap_size = array_size;
    for (int i = array_size; i >= 2; i--) {
        int tmp = array[1];
        array[1] = array[i];
        array[i] = tmp;
        heap_size -= 1;
        max_heapify(array, 1, heap_size);
    }
}

// ================================================================
// quick sort
// ================================================================
void quick_sort(int *array, int head, int tail){
    if (head >= tail){
        return;
    }
            
    int tmp = array[head];
    int l = head + 1;
    int r = tail;
    int t;
    while (l != r) {
        while (array[r] >= tmp && l < r) {
            r--;
        }
        while (array[l] <= tmp && l < r) {
            l++;
        }
        if (l < r) {
            t = array[l];
            array[l] = array[r];
            array[r] = t;
        }
    }
    array[head] = array[l];
    array[l] = tmp;
    quick_sort(array, head, l - 1);
    quick_sort(array, l + 1, tail);
}
