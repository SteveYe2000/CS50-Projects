#include <cs50.h>
#include <stdio.h>

void print_pyramid(int h);
int main(void)
{
    int n;
    do {
        n = get_int("Please enter height: ");
    }
    while (n > 9 || n < 0);
    print_pyramid(n);
}


void print_pyramid(int h)
{
    for (int i = 0; i < h + 1; i++) {
        for (int j = h; j > 0; j--) {
            if (i < j) {
                printf(" ");
            }
            else {
                printf("#");
            }
        }
    printf("  ");
        for (int y = 0; y < i; y++) {
            printf("#");
        }
    printf("\n");
    }
}


