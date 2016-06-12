#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "sort.h"

int main(int argc, char *argv[])
{   
#ifdef RELEASE
    if (argc != 3) {
        printf("usage:\n");
        printf("\tsort <filein> <fileout>\n");
        return -1;
    }
    FILE *fin = fopen(argv[1], "r");
    if (NULL == fin) {
        printf("open error\n");
        return -1;
    }
    char sep;
    int numb = 0;
    do {
        sep = fgetc(fin);
        if ( sep == ',')
            numb++; // get the count of the numbers in the input file
    } while (EOF != sep);
    printf("count of numbers in file \"%s\" is %d\n", argv[1], numb);
    fseek(fin, 0, SEEK_SET);
    int * iout = (int*)malloc(sizeof(int) * numb);
    int *p = iout;
    while (!feof(fin)) {
        int a;
        fscanf(fin, "%d,", &a);
        *p++ = a;
    }
    fclose(fin);
    
    // ======================================
    // sort functions
    // ======================================
    //insertion_sort(iout, numb);
    //merge_sort(iout, 0, numb - 1);
    //bubble_sort(iout, numb);
    //heap_sort(iout - 1, numb);
    quick_sort(iout, 0, numb - 1);
    


    FILE * fout = fopen(argv[2], "w");
    for (int i = 0; i < numb; i++) {
        fprintf(fout, "%d,", *(iout + i));
    }
    fclose(fout);
#endif

#ifdef DEBUG
    int a[10] = {3, 5, 7, 9, 2, 8, 6, 4, 1, 0};
    //merge_sort(a, 0, 9);
    //bubble_sort(a, 10);
    //heap_sort(a-1, 10);
    quick_sort(a, 0, 9);
    for(int i = 0; i < 10; ++i) {
        printf("%d, ", a[i]);
    }
    putchar('\n');





    //int b[10] = {1, 3, 5, 700, 900, 2, 4, 6, 8, 10};
    //int c[2] = { 9, 2 };
    //merge(c, 0, 0, 1);
    //merge(b, 0, 4, 9);
    //for(int i = 0; i < 2; ++i) {
    //    printf("%d, ", c[i]);
    //}
    //putchar('\n');
    //for(int i = 0; i < 10; ++i) {
    //    printf("%d, ", b[i]);
    //}
    //putchar('\n');
#endif
}
