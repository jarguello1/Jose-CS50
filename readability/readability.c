#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float count_letters(string text, int words);
float count_sentences(string text, int words);
int count_words(string text);


int main(void)
{
    //Prompt user for Text to examine
    string text = get_string("Text: ");

    //count the number of words in the text
    int words = count_words(text);

    //count the number of sentences in the text
    float sentences = count_sentences(text, words);

    //count the number of letters in the text
    float letters = count_letters(text, words);

    //calculate using Coleman-Liau index
    //CL_index = 0.0588 * L - 0.296 * S - 15.8
    float grade_level = (0.0588 * letters) - (0.296 * sentences) - 15.8;
    int rounded_grade = (int) round(grade_level);

    //check what grade level is less than 1 or greater than 16 for special printf
    //for every other grade level print grade level
    if (rounded_grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (rounded_grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", rounded_grade);
    }
}

//count the number of words in the passage using the number of spaces and then adding 1
int count_words(string text)
{
    int words = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

//count the number of letters and then return the average letters based on the number of words
float count_letters(string text, int words)
{
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    float average_letters = (float) letters / words * 100;
    return average_letters;

}

//count the number of sentences and then return the average sentences based on the number of words
float count_sentences(string text, int words)
{
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.')
        {
            sentences++;
        }
        else if (text[i] == '!')
        {
            sentences++;
        }
        else if (text[i] == '?')
        {
            sentences++;
        }
    }

    float average_sentences = (float) sentences / words * 100;
    return average_sentences;
}