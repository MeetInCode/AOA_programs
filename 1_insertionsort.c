#include <stdio.h>
#include <time.h>

int main()
{
    int arr[] = {5, 2, 9, 1, 5, 6}; // Array to sort
    int n = 6;                      // Number of elements
    int i, j, key;

    clock_t start, end;            // Variables to store start and end time
    double cpu_time_used;

    start = clock();               // Start the timer

    // Insertion Sort
    for (i = 1; i < n; i++)
    {
        key = arr[i]; // Store the value to insert
        j = i - 1;    // Start comparing from the previous element

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key; // Insert key at the correct position
    }

    end = clock(); // End the timer

    // Time calculation
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %f seconds\n", cpu_time_used);

    return 0;
}

