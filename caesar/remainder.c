#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //find the remainder
    int number = get_int("Input a number: \n");
    int remainder = get_int("Input a remainder: \n");

    printf("%i\n", number % remainder);
}