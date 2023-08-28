#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n; // prompt for start size
    do
    {
       n = get_int("Start size: ");
    }
    while (n < 9);

    int y; // prompt for end size
    do
    {
       y = get_int("End size: ");
    }
    while (y < n);

    int years = 0; // number of years

    while (n < y)
    {
      n += n / 3 - n / 4;
      years++;
    }

   printf("Years: %i\n", years); // print number of years