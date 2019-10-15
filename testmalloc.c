#include "./includes/malloc.h"

int main()
{
    printf("%zu\n", (size_t)malloc(5));
    printf("%zu\n", (size_t)malloc(2));

    return 0;
}