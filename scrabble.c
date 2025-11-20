#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculate_points(string letter);

int main(void)
{
    string letter1 = get_string("Player 1: ");
    string letter2 = get_string("Player 2: ");

    int points1 = calculate_points(letter1);
    int points2 = calculate_points(letter2);

    if (points1 > points2)
    {
        printf("Player 1 wins!\n");
    }
    else if (points2 > points1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int calculate_points(string letter)
{
    int len = strlen(letter);
    int total_points = 0;

    for (int i = 0; i < len; i++)
    {
        if (isupper(letter[i]))
        {
            total_points += points[letter[i] - 'A'];
        }
        else if (islower(letter[i]))
        {
            total_points += points[letter[i] - 'a'];
        }
    }
    return total_points;
}
