#include <cs50.h>
#include <stdio.h>
#include <math.h>


//Todo
//Prompt for input
//Calculate checksum
//Check for card length and starting digits
//Print card type or invalid
string credit(long number);

int main(void)
{
    long n;
    long full_number;
    int ccnum;
    int ccnum1;
    int ccnum2;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    // Ask for credit card number
    do
    {
        n = get_long("Credit Card Number: ");
        full_number = n;
    }
    while (n < 0);

    // Checksum calculator
    do
    {
        // take the remainder, add to sum1, divide credit card number by 10
        ccnum = n % 10;
        sum1 += ccnum;
        n /= 10;

        // take the remainder, multiply by two, split digits if necessary, add to sum2, divide credit card number by 10
        ccnum = n % 10;
        ccnum2 = ccnum * 2;
        if (ccnum2 > 9)
        {
            sum2 += (ccnum2 - 9);
        }
        else
        {
            sum2 += (ccnum2);
        }
        n /= 10;
    }
    while (n > 0);

    // add sum1 and sum2 togther
    sum3 = (sum1 + sum2);

    // if sum isn't divisible by 10 print invalid
    if (sum3 % 10 != 0)
    {
        printf("INVALID\n");
    }
    // if sum is divisible by 10 proceed to check if it's a valid credit card
    else
    {
        string result = credit(full_number);
        printf("%s\n", result);
    }

}

string credit(long number)
{
    // count ccnum length
    int length = 0;
    long start_number = number;
    long ccnum = number;
    while (ccnum > 0)
    {
        ccnum /= 10;
        length++;
    }
    //assign start number
    while (start_number > 99)
    {
        start_number /= 10;
    }

    //check if number is valid length

    if ((length == 13 || length == 16) && (start_number > 39 && start_number < 50))
    {
        return "VISA";
    }
    if ((length == 16) && (start_number > 50 && start_number < 56))
    {
        return "MASTERCARD";
    }
    if ((length == 15) && (start_number == 34 || start_number == 37))
    {
        return "AMEX";
    }
    if (length != 13 && length != 15 && length != 16)
    {
        return "INVALID";
    }
    else
    {
        return "INVALID";
    }
}