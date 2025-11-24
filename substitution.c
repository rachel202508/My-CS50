#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_ciphertext(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        int n = strlen(argv[1]);
        if (n != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            int l[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (int i = 0; i < 26; i++)
            {
                if (isalpha(argv[1][i]))
                {
                    char c = toupper(argv[1][i]);
                    l[c - 'A']++;
                }
                else
                {
                    return 1;
                    break;
                }
            }
            for (int j = 0; j < 26; j++)
            {
                if (l[j] == 2)
                {
                    return 1;
                    break;
                }
            }
        }
    }
    string plaintext = get_string("plaintext: ");
    print_ciphertext(plaintext, argv[1]);
}

void print_ciphertext(string plaintext, string key)
{
    string ciphertext = plaintext;
    for (int k = 0, l = strlen(plaintext); k < l; k++)
    {

        char c = plaintext[k];
        if (isalpha(c))
        {
            if (islower(c))
            {
                ciphertext[k] = tolower(key[c - 'a']);
            }
            else if (isupper(c))
            {
                ciphertext[k] = toupper(key[c - 'A']);
            }
        }
    }
    printf("ciphertext: %s\n", ciphertext);
}
