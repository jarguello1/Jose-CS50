#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Make sure the program only accepts one argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        //if any character in argv isnt a digit return
        if (isdigit(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        int count;
        for (int j = 0; j < len; j++)
        {
            count = 1;
            for (int k = j + 1; k < len; k++)
            {
                if (argv[1][j] == argv[1][k] && argv[1][k] != ' ')
                {
                    count++;
                    argv[1][k] = '0';
                }
            }
            if (count > 1 && argv[1][i] != '0')
            {
                return 1;
            }
        }
    }
    if (argc == 2 && isalpha(*argv[1]) && strlen(argv[1]) == 26)
    {
        string cipher_key = argv[1];
        string plain_text = get_string("plain_text:  ");
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plain_text); i++)
        {
            if (isupper(plain_text[i]))
            {
                int letter_value = plain_text[i] - 'A';
                printf("%c", toupper(cipher_key[letter_value]));
            }
            else if (islower(plain_text[i]))
            {
                int letter_value = plain_text[i] - 'a';
                printf("%c", tolower(cipher_key[letter_value]));
            }
            else
            {
                printf("%c", plain_text[i]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

}