#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    char path[100];
    char type[10];
    int min;
    int max;
    int numb;
    char separator[10];
    
    printf("Please input the whole path of file:\n");
    scanf("%s", path);
    printf("You want to generate \"int\" or \"float\"?\ntype \"int\" or \"float\":\n");
    scanf("%s", type);
    if ( strncmp("int", type, 3) && strncmp("float", type, 5)) {
        printf("ERROR: unknow type : %s\n", type);
        return 0;
    }
    printf("the minimum value of the generated numbers:");
    scanf("%d", &min);
    printf("the maximum value of the generated numbers:");
    scanf("%d", &max);
    printf("the number you want to generate:");
    scanf("%d", &numb);
    printf("the separator:");
    scanf("%s", separator);
#if 0
    printf("parameters:\n");
    printf("path: %s\n", path);
    printf("type: %s\n", type);
    printf("min:  %d\n", min);
    printf("max:  %d\n", max);
    printf("numb: %d\n", numb);
    printf("separator: %s\n", separator);
#endif
    
    FILE * f = fopen(path, "w");
    srand((unsigned)time(NULL));
    int range = max - min;
    for (int i = 0; i < numb; i++) {
        if ( !strncmp("int", type, 3) )
            fprintf(f, "%d%s", rand() % range + min, separator);
        else if ( !strncmp("float", type, 5) ) {
            double rdnumb = (rand() % (range * 100) / 100.00) + min;
            fprintf(f, "%f%s", rdnumb, separator);
        }
    }
    fclose(f);
}
