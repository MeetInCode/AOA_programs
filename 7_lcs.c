#include <stdio.h>
#include <string.h>

// Global strings
char str1[] = "AGGTAB";
char str2[] = "GXTXAYB";

// Lengths of the strings
int len1 = 6;
int len2 = 7;

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find LCS length using recursion
int findLCSLength(int i, int j) {
    // Base case: if any string is empty, LCS length is 0
    if (i == 0 || j == 0)
        return 0;

    // If characters match, move diagonally ↖️
    if (str1[i - 1] == str2[j - 1]) {
        return 1 + findLCSLength(i - 1, j - 1);  // Diagonal ↖️
    } else {
        // Else, move left ← or up ↑ and take the maximum
        int left = findLCSLength(i, j - 1);      // Left ←
        int up   = findLCSLength(i - 1, j);      // Up ↑
        return max(left, up);
    }
}

// Function to construct the LCS string using recursion
void constructLCS(int i, int j, char* lcs) {
    // Base case: if any string is empty, stop
    if (i == 0 || j == 0)
        return;

    // If characters match, include this character in LCS string and move diagonally ↖️
    if (str1[i - 1] == str2[j - 1]) {
        lcs[strlen(lcs)] = str1[i - 1];  // Add matching character to LCS
        constructLCS(i - 1, j - 1, lcs);  // Diagonal ↖️
    } else {
        // Else, move left ← or up ↑ based on where we get the better result
        if (findLCSLength(i, j - 1) > findLCSLength(i - 1, j)) {
            constructLCS(i, j - 1, lcs);  // Move left ←
        } else {
            constructLCS(i - 1, j, lcs);  // Move up ↑
        }
    }
}

int main() {
    // Step 1: Calculate the length of LCS
    int lcsLength = findLCSLength(len1, len2);
    printf("Length of LCS = %d\n", lcsLength);

    // Step 2: Construct the actual LCS string
    char lcs[lcsLength + 1];  // Array to store the LCS string
    lcs[0] = '\0';  // Initialize the string as empty

    // Construct LCS from the end of both strings
    constructLCS(len1, len2, lcs);

    // Step 3: Print the LCS string
    printf("LCS string = %s\n", lcs);

    return 0;
}
