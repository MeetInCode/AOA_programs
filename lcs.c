#include <stdio.h>
#include <string.h>

// Function to return the maximum of two numbers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    // Input strings
    char str1[] = "stone";
    char str2[] = "longest";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // DP table to store lengths of LCS
    int dp[100][100];

    // Fill the DP table
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0; // First row or column = 0
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1; // Characters match
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Take max
        }
    }

    // Backtrack to build the LCS string
    int lcsLength = dp[len1][len2];
    char lcs[100];
    lcs[lcsLength] = '\0'; // Null-terminate the string

    int i = len1, j = len2;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs[lcsLength - 1] = str1[i - 1]; // Add to LCS
            i--;
            j--;
            lcsLength--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--; // Move up
        }
        else
        {
            j--; // Move left
        }
    }

    // Output
    printf("Length of LCS: %d\n", dp[len1][len2]);
    printf("LCS: %s\n", lcs);

    return 0;
} 