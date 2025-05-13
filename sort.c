#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void main() {
    int arr[5];
    int i, n;

    clrscr();  // Clear the screen

    n = 5;
    printf("Enter 5 integers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nHello World");

    getch();  // Wait for key press
}
