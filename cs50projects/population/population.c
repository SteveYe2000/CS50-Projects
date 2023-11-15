#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Prompt for start size
    long population_size;
    do {
        population_size = get_long("Population Size: ");
    }
    while (population_size < 9 || population_size < 0);

    // TODO: Prompt for end size
    long end_population_size;
    do {
        end_population_size = get_long("Ending Population Size: ");
    }
    while (end_population_size < population_size);

    // TODO: Calculate number of years until we reach threshold
    long current = population_size;
    long years = 0;
    while (current < end_population_size) {
        long new_borns = round(current / 3);
        long pass_aways = round(current / 4);
        current = current + new_borns - pass_aways;
        years += 1;
    }

    // TODO: Print number of years
    printf("Years: %li\n", years);
}
