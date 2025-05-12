#include <stdio.h>
#include <string.h>

#define MAX 100 // Maximum size for text and pattern

// Global arrays to store the text, pattern, and LPS array
char text[MAX], pattern[MAX];
int lps[MAX];

// Function to compute the LPS (Longest Prefix Suffix) array
void computeLPSArray()
{
    int curr_len = 0; // Length of the current longest prefix-suffix
    lps[0] = 0;       // LPS of the first character is always 0
    int i = 1;

    // Loop through the pattern to compute the LPS array
    while (pattern[i] != '\0')
    {
        if (pattern[i] == pattern[curr_len])
        {
            curr_len++;        // Increase length of the current prefix-suffix
            lps[i] = curr_len; // Store the length in the LPS array
            i++;               // Move to the next character in the pattern
        }
        else
        {
            if (curr_len != 0)
            {
                // If mismatch occurs and we have some prefix-suffix match already
                curr_len = lps[curr_len - 1]; // Fall back to a shorter prefix
                // Note: We don't increment i here - we'll try again with the shorter prefix
            }
            else
            {
                // If no previous match (length=0), we can't fall back further
                lps[i] = 0; // No match, set LPS[i] to 0
                i++;        // Move to the next character in the pattern
            }
        }
    }
}

// Function to perform KMP string matching
void KMPSearch()
{
    int i = 0, j = 0; // i is index for text, j is index for pattern

    // Loop through the text to find the pattern
    while (text[i] != '\0')
    {
        // If characters match, move to the next character in both text and pattern
        if (pattern[j] == text[i])
        {
            i++; // Move to the next character in the text
            j++; // Move to the next character in the pattern
        }

        // If we've matched the entire pattern
        if (pattern[j] == '\0')
        {
            printf("Pattern found at index %d\n", i - j); // Print the match position
            j = lps[j - 1];                               // Use the LPS array to avoid unnecessary comparisons
        }
        // If there's a mismatch
        else if (text[i] != '\0' && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1]; // Use LPS to skip ahead in the pattern
            }
            else
            {
                i++; // Move to the next character in the text
            }
        }
    }
}

int main()
{
    // Sample text and pattern
    strcpy(text, "ABABDABACDABABCABAB");
    strcpy(pattern, "ABABCABAB");

    // Step 1: Compute the LPS array for the pattern
    computeLPSArray();

    // Step 2: Perform the KMP search to find the pattern in the text
    KMPSearch();

    return 0;
}
