#ifndef SORT_H_
#define SORT_H_

//#define DEBUG
#define RELEASE

void insertion_sort(int * array, int size);

#ifdef DEBUG
void merge(int * array, int head, int middle, int tail);

void max_heapify(int *array, int node, int array_size);
void build_max_heap(int *array, int array_size);
#endif

void merge_sort(int *array, int head, int tail);

void bubble_sort(int * array, int size);

void heap_sort(int *array, int size);

#endif
