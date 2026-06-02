#include <stdio.h>
#include "../cs50.h"
#include "../cs50.c"

/** PROBLEM SET 1 - MARIO (C)
 * CATCHES:
 * No dynamic string representation supported in C.
 * No built-in function to check the data type of variables at runtime.
 */

// Declare helper functions at the top for the compiler
void printRow(int spaces, int bricks);

// Program entry point
int main(void)
{
    int height;

    // Keep prompting the user for height if it's invalid
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    // Print pyramid
    for (int i = 1; i < height + 1; i++)
    {
        printRow(height, i);
    }
}

// Helper function
void printRow(int height, int bricks)
{
    // Spaces
    for (int k = 0; k < height - bricks; k++)
    {
        printf(" ");
    }

    // Bricks
    for (int j = 0; j < bricks; j++)
    {
        printf("#");
    }

    printf("\n");   // Rows
}