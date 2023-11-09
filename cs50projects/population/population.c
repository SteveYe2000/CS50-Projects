#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    long population_size;
    do {
        population_size = get_int("Population Size: ");
    }
    while (population_size < 9);

    // TODO: Prompt for end size
    long end_population_size;
    do {
        end_population_size = get_int("Ending Population Size: ");
    }
    while (end_population_size < population_size);

    // TODO: Calculate number of years until we reach threshold
    long current = 0;
    long years = 0;
    while (current < end_population_size)
    {
        long new_borns = population_size / 3;
        long pass_aways = population_size / 4;
        current += population_size + new_borns - pass_aways;
        years += end_population_size / current;
    }

    // TODO: Print number of years
    printf("Years: %licode\n", years);
}
