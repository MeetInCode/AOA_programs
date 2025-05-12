#include <stdio.h>
#include <string.h>

// Global strings and their lengths
char str1[] = "AGGTAB";
char str2[] = "GXTXAYB";
int len1 = 6, len2 = 7;
int dp[7][8]; // DP table to store LCS lengths

// Function to find the maximum of two numbers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to find the length of the LCS using dynamic programming
void findLCSLength()
{
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            // If either string is empty, LCS length is 0
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            // If characters match, LCS length increases
            else if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // If no match, take the maximum of left or top cell
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

// Function to construct and print the LCS string
void printLCS()
{
    int i = len1, j = len2;
    char lcs[dp[len1][len2] + 1]; // Array to store the LCS string
    int index = 0;

    // Trace back to build the LCS string from the DP table
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs[index++] = str1[i - 1]; // Add matching character to LCS
            i--;
            j--;
        }
        // If no match, move to the larger value (up or left)
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    lcs[index] = '\0'; // Null-terminate the LCS string

    // Print the LCS string in reverse order
    for (int k = index - 1; k >= 0; k--)
    {
        printf("%c", lcs[k]);
    }
    printf("\n");
}

int main()
{
    findLCSLength(); // Compute the LCS length using dynamic programming
    printf("Length of LCS = %d\n", dp[len1][len2]);
    printf("LCS string = ");
    printLCS(); // Construct and print the LCS string
    return 0;
}
