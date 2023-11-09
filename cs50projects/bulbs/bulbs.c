#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string message = get_string("Message: ");
    for (int j = 0; j < strlen(message); j++) {
        char message_in_binary[] = "00000000";
        int index = 0;
        int result = message[j];
        while (result != 0) {
            for (int i = 7; i > -1; i--) {
                if (result < ((int) pow(2, i))) {
                    index += 1;
                }
                else {
                    result -= (int) pow (2, i);
                    message_in_binary[index] = '1';
                }
            }
            for (int x = 0; x < 8; x++) {
                print_bulb(message_in_binary[x]);
            }
        printf("\n");
        }
    }
}

void print_bulb(int bit)
{
    if (bit == '0')
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == '1')
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

