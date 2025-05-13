#include <stdio.h>
#include <string.h>

void main() {
    char text[100], pattern[50];
    char *ptr;

    clrscr();  // Clears screen in Turbo C

    printf("Enter the main text: ");
    gets(text);  // Unsafe in modern compilers, allowed in Turbo C

    printf("Enter the pattern to search: ");
    gets(pattern);

    ptr = strstr(text, pattern);

    if (ptr != NULL)
        printf("Pattern found at position: %d\n", ptr - text + 1);
    else
        printf("Pattern not found.\n");

    getch();  // Waits for a keypress (Turbo C)
}
