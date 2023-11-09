#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    // input for weeks
    int weeks;
    do {
        weeks = get_int("Numbers of weeks taking CS50: ");
    }
    while (weeks > 12 || weeks < 1);

    // calculating hours for total weeks
    int sum = 0;
    for (int i = 0; i < weeks; i++) {
        int hour = get_int("Week %i HW Hours: ", i);
        sum += hour;
    }

    // average
    float average = sum / weeks;

    // total hours
    float total = sum;

    // ask T or A
    char letter = get_char("Enter T for total hours, A for average hours per week: ");
    while (letter != 'T' && letter != 'A') {
        letter = get_char("Enter T for total hours, A for average hours per week: ");
    }
    if (letter == 'T') {
        printf("%.2f hours!\n", total);
    }
    else {
        printf("%.2f hours!\n", average);
    }

}

