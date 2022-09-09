#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Incorrect Amount of Arguments.\n");
        return 1;
    }
    // Make sure every character in argv[1] is a digit
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        //if any character in argv isnt a digit return 1
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    if (argc == 2 && isdigit(*argv[1]))
    {
        // Convert argv[1] from a `string` to an `int`
        int cipher_key = atoi(argv[1]);
        // Prompt user for plaintext
        string s = get_string("plaintext:  ");
        printf("ciphertext: ");
        // For each character in the plaintext:
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            //for uppercase characters replace character with cipher keys
            if (isupper(s[i]))
            {
                if (s[i] + (cipher_key % 26) > 'Z')
                {
                    printfcd ..("%c", s[i] + (cipher_key % 26) - 26);
                }
                else
                {
                    printf("%c", s[i] + (cipher_key % 26));
                }
            }
            //for lowercase characters replace character with cipher keys
            else if (islower(s[i]))
            {
                if (s[i] + (cipher_key % 26) > 'z')
                {
                    printf("%c", s[i] + (cipher_key % 26) - 26);
                }
                else
                {
                    printf("%c", s[i] + (cipher_key % 26));
                }
            }
            else
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

