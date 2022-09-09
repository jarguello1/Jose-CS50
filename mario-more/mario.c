#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while ((n < 1) || (n > 8)) ;

    // for each row
    for (int i = 0; i < n; i++)
    {
        //spaces before the blocks to make middle gap even
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        // for each column
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // space between blocks
        printf("  ");
        // for each column
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // move to next row
        printf("\n");
    }
}