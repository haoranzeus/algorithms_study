#include <stdio.h>


int binary_search(int *array, int size, int item) {
    int low = 0;     // low和high用于跟踪要在其中查找的列表部分
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high); // 2
        int guess = array[mid];
        if (guess == item) {
            return mid;
        }
        if (guess > item) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    int mylist[5] = {1, 3, 5, 7, 9};
    printf("%d\n", binary_search(mylist, 5, 3));
    printf("%d\n", binary_search(mylist, 5, -1));
}
