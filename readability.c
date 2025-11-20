#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int calculate_letters(string text);
int calculate_words(string text);
int calculate_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = calculate_letters(text);
    int words = calculate_words(text);
    int sentences = calculate_sentences(text);

    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentences / (float) words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int calculate_letters(string text)
{
    int len = strlen(text);
    int number_of_letters = 0;

    for (int i = 0; i < len; i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            number_of_letters++;
        }
    }
    return number_of_letters;
}

int calculate_words(string text)
{
    int len = strlen(text);
    int number_of_words = 1;

    for (int k = 0; k < len; k++)
    {
        if (text[k] == ' ')
        {
            number_of_words++;
        }
    }
    return number_of_words;
}

int calculate_sentences(string text)
{
    int len = strlen(text);
    int number_of_sentences = 0;

    for (int j = 0; j < len; j++)
    {
        if (text[j] == '!' || text[j] == '?' || text[j] == '.')
        {
            number_of_sentences++;
        }
    }
    return number_of_sentences;
}
