#include "insertion.h"

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
