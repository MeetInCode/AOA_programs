#include <stdio.h>
#include <string.h>

// Step 1: Compute the Longest Prefix Suffix (LPS) array
// LPS[i] stores the length of the longest proper prefix that is also a suffix for pattern[0..i]
void computeLPS(char pattern[], int lps[])
{
    int prefixLength = 0; // Length of the longest prefix-suffix
    int i = 1;            // Start from the second character of the pattern
    lps[0] = 0;           // First element is always 0

    while (pattern[i] != '\0')
    {
        if (pattern[i] == pattern[prefixLength])
        {
            // If characters match, increase the prefix length
            prefixLength++;
            lps[i] = prefixLength;
            i++;
        }
        else
        {
            // If characters mismatch, check the previous prefix length
            if (prefixLength != 0)
            {
                prefixLength = lps[prefixLength - 1]; // Move back to the previous valid prefix
            }
            else
            {
                lps[i] = 0; // No valid prefix found, set LPS[i] to 0
                i++;
            }
        }
    }
}

// Step 2: Search for pattern in the text using the KMP algorithm
void searchPattern(char text[], char pattern[])
{
    int i = 0, j = 0;                    // i for text[], j for pattern[]
    int textLength = strlen(text);       // Length of the text
    int patternLength = strlen(pattern); // Length of the pattern
    int lps[100];                        // Array to store the LPS values (assuming max size 100)

    // Preprocess the pattern to fill the LPS array
    computeLPS(pattern, lps);

    // Start searching through the text
    while (i < textLength)
    {
        if (text[i] == pattern[j])
        {
            // If characters match, move both indices forward
            i++;
            j++;
        }

        // If the entire pattern is matched
        if (j == patternLength)
        {
            printf("Pattern found at index %d\n", i - j);
            // Use the LPS array to skip unnecessary comparisons
            j = lps[j - 1];
        }
        // If there is a mismatch after some matches
        else if (i < textLength && text[i] != pattern[j])
        {
            if (j != 0)
            {
                // Use LPS to skip the pattern part we already know matches
                j = lps[j - 1];
            }
            else
            {
                // If no matches at all, just move forward in the text
                i++;
            }
        }
    }
}

int main()
{
    char text[] = "abxabcabcaby"; // The text to search in
    char pattern[] = "abcaby";    // The pattern to search for

    // Call the search function to find the pattern in the text
    searchPattern(text, pattern);

    return 0;
}
