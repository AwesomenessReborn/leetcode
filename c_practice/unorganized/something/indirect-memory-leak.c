#include <stdlib.h>
#include <stdio.h>

int main()
{

    void *x = malloc(8), *y = malloc(8);
    *(void **)x = y; // in a cycle. Indirect leak
    *(void **)y = x; // in a cycle. Indirect leak
    printf("%p %p\n", x, y);

    return 0;
}