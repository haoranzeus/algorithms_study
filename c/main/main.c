#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "insertion.h"

int main(int argc, char *argv[])
{   
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

    // sort
    insertion_sort(iout, numb);
    FILE * fout = fopen(argv[2], "w");
    for (int i = 0; i < numb; i++) {
        fprintf(fout, "%d,", *(iout + i));
    }
    fclose(fout);
}
