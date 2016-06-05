#ifndef SORT_H_
#define SORT_H_

//#define DEBUG
#define RELEASE

void insertion_sort(int * array, int size);

#ifdef DEBUG
void merge(int * array, int head, int middle, int tail);
#endif

void merge_sort(int *array, int head, int tail);

void bubble_sort(int * array, int size);

#endif
