#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void test_pointer() {
    int *a;
    int *b;

    printf("OUI\n");
    b = (int*)malloc(sizeof(int) * 1);
    *b = 10;
    printf("[AVANT] Valeur de b: %d\n", *b);
    a = b;
    *a = 5;
    printf("[APRES] Valeur de b: %d\n", *b);
}

int main() {
    test_pointer();

    return 0;
}