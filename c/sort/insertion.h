#ifndef INSERTION_H_
#define INSERTION_H_

//#define DEBUG
#define RELEASE

void insertion_sort(int * array, int numb);

#ifdef DEBUG
void merge(int * array, int head, int middle, int tail);
#endif

void merge_sort(int *array, int head, int tail);

#endif
