#include <stdio.h>

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;
    int i, j, min, temp;

    // Go through each element except the last
    for (i = 0; i < n-1; i++) {
        min = i; // Assume current element is the smallest

        // Find the smallest element in the rest of the array
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j; // Update if we find a smaller element
            }
        }

        // Swap the found smallest with the current element
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    // Print the sorted array
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
