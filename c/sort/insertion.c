#include <stdlib.h>
#include <malloc.h>
#include "insertion.h"

// ================================================================
// insertion sort
// ================================================================
void insertion_sort(int * array, int numb){
    int key, i;
    for (int j = 1; j < numb; j++) {
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
