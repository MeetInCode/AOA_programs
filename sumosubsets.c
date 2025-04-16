#include <stdio.h>

#define MAX 100

int arr[MAX];     // Input elements
int subset[MAX];  // Current subset being formed
int n;            // Number of elements
int targetSum;    // Required sum
int totalSum = 0; // Sum of all elements

// Function to print a subset
void printSubset(int size)
{
    printf("{ ");
    for (int i = 0; i < size; i++)
        printf("%d ", subset[i]);
    printf("}\n");
}

// Recursive function to find subsets
void findSubsets(int index, int currentSum, int subsetSize, int remainingSum)
{
    // If current subset matches target sum, print it
    if (currentSum == targetSum)
    {
        printSubset(subsetSize);
        return;
    }

    // Prune if:
    // - no more elements
    // - current sum too big
    // - not enough left to reach target
    if (index == n || currentSum > targetSum || currentSum + remainingSum < targetSum)
        return;

    // Include current element
    subset[subsetSize] = arr[index];
    findSubsets(index + 1, currentSum + arr[index], subsetSize + 1, remainingSum - arr[index]);

    // Exclude current element
    findSubsets(index + 1, currentSum, subsetSize, remainingSum - arr[index]);
}

int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        totalSum += arr[i];
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("Subsets that sum to %d are:\n", targetSum);
    findSubsets(0, 0, 0, totalSum);

    return 0;
}
