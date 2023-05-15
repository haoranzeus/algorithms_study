#include <stdio.h>

int find_smallest(int *arr, int size) {
    int smallest = arr[0];      // 存储最小值
    int smallest_index = 0;     // 存储最小元素的索引
    for (int i; i < size; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
            smallest_index = i;
        }
    }
    return smallest_index;
}

int * select_sort(int *arr, int size) {
    int new_arr[size];
    for(int i; i < size; i++) {

    }
}
