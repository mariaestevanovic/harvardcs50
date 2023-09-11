#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool validate_key(string key);
void substitute(string text, string key);

int main(int argc, string argv[])
{
    if (argc != 2 || !validate_key(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    string plaintext = get_string("plaintext: ");
    substitute(plaintext, key);

    return 0;
}

bool validate_key(string key)
{
    int len = strlen(key);

    if (len != 26)
    {
        return false;
    }

    bool used[26] = {false};

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = toupper(key[i]) - 'A';

        if (used[index])
        {
            return false;
        }

        used[index] = true;
    }

    return true;
}

void substitute(string text, string key)
{
    int len = strlen(text);

    printf("ciphertext: ");

    for (int i = 0; i < len; i++)
    {
        char c = text[i];

        if (isalpha(c))
        {
            char shift = isupper(c) ? 'A' : 'a';
            int index = toupper(c) - 'A';
            char substituted = toupper(key[index]);

            if (islower(c))
            {
                substituted = tolower(substituted);
            }

            printf("%c", substituted);
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
}