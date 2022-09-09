#include <stdio.h>
#include <cs50.h>

int main(void)
{
    {
        int i = get_negative_int();
        printf("$i\n", i);
    }
}

int get_negative_int(void)
{
    // has an error with negative ints because they are lower than 0
    int n;
    do
    {
        n = get_int("Negative Integer: ");
    }
    while(n < 0);
    return n;
}