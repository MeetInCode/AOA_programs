#include <stdio.h>

#define N 4  // Number of elements in the set

int set[N] = {10, 7, 5, 18};  // The input set
int target = 20;              // Target sum

// Simple function to check if there exists a subset with sum = target
int sumOfSubsets(int pos, int currentSum) {
    if (currentSum == target) {
        return 1;  // Found a subset with the target sum
    }
    if (pos == N) {
        return 0;  // Reached the end of the set, no subset found
    }

    // Include set[pos] in the current subset
    if (sumOfSubsets(pos + 1, currentSum + set[pos])) {
        return 1;
    }

    // Exclude set[pos] from the current subset
    return sumOfSubsets(pos + 1, currentSum);
}

int main() {
    if (sumOfSubsets(0, 0)) {
        printf("Subset found with sum %d\n", target);
    } else {
        printf("No subset found with sum %d\n", target);
    }
    return 0;
}
