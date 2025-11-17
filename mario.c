#include <cs50.h>
#include <stdio.h>

void print_spaces(int spaces);
void print_first_block(int bricks1);
void print_gap();
void print_second_block(int bricks2);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        print_spaces(n - i - 1);
        print_first_block(i + 1);
        print_gap();
        print_second_block(i + 1);
    }
}

void print_spaces(int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
}

void print_first_block(int bricks1)
{
    for (int k = 0; k < bricks1; k++)
    {
        printf("#");
    }
}

void print_gap()
{
    for (int m = 0; m < 2; m++)
    {
        printf(" ");
    }
}

void print_second_block(int bricks2)
{
    for (int n = 0; n < bricks2; n++)
    {
        printf("#");
    }
    printf("\n");
}
