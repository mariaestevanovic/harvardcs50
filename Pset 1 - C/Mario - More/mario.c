#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int k = n - i - 1; k > 0; k--)
        {
            printf(" ");
        }
        for (int j = 1; j <= i + 1; j++)
        {
            printf("#");
        }
        {
            printf("  ");
        }
        for (int l = 1; l <= i + 1; l++)
        {
            printf("#");
        }
        printf("\n");
    }

}