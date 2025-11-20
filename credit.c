#include <cs50.h>
#include <stdio.h>

int calculate_sum(long number);
int calculate_number_of_digits(long number);
void check_validity(long number, int number_of_digits, int sum);

int main(void)
{
    long number;
    number = get_long("Number: ");

    int sum = calculate_sum(number);
    int number_of_digits = calculate_number_of_digits(number);
    check_validity(number, number_of_digits, sum);
}

int calculate_sum(long number)
{
    int number_of_digits = 1;
    int sum = 0;
    int digit;
    while (number > 0)
    {
        if (number_of_digits % 2 == 0)
        {
            digit = (number % 10) * 2;
            number = number / 10;
            number_of_digits++;
            if (digit >= 10)
            {
                digit = digit % 10;
                sum += digit;
                sum++;
            }
            else
            {
                sum += digit;
            }
        }
        else if (number_of_digits % 2 == 1)
        {
            digit = number % 10;
            sum += digit;
            number = number / 10;
            number_of_digits++;
        }
    }
    number_of_digits--;
    return sum;
}

int calculate_number_of_digits(long number)
{
    int number_of_digits = 0;
    while (number > 0)
    {
        number = number / 10;
        number_of_digits++;
    }
    return number_of_digits;
}

void check_validity(long number, int number_of_digits, int sum)
{
    if (sum % 10 == 0)
    {
        if ((number_of_digits == 13) && (number / 1000000000000 == 4))
        {
            printf("VISA\n");
        }
        else if ((number_of_digits == 15) &&
                 ((number / 10000000000000 == 34) || (number / 10000000000000 == 37)))
        {
            printf("AMEX\n");
        }
        else if (number_of_digits == 16)
        {
            if (number / 1000000000000000 == 4)
            {
                printf("VISA\n");
            }
            else if ((number / 100000000000000 == 51) || (number / 100000000000000 == 52) ||
                     (number / 100000000000000 == 53) || (number / 100000000000000 == 54) ||
                     (number / 100000000000000 == 55))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
