#include <cs50.h>
#include <stdio.h>
#include <math.h>

int len(long long length);
int split_sum(int num);
int main(void)
{

    // getting input
    long long n;
    do {
        n = get_long("Please enter your card number: ");
    }
    while (len(n) < 12 || len(n) > 17);

    int l = len(n);
    int sum_1 = 0;
    int sum_2 = 0;
    int total = 0;
    int arr[16] = {};

    // converting n into list
    for (int x = 0; x < l; x++) {

        long long first = n / pow(10, len(n)-x-1);

        if (x == 0) {
            arr[x] = n / pow(10, len(n)-x-1);
        }
        else {
            arr[x] = first % 10;
        }
    }

    // sum for every other 2 digits * 2
    for (int i = 0; i < l; i += 2) {
        int temp_num = 0;
        if (arr[i] > 4) {
            temp_num += split_sum(arr[i]);
            sum_1 += temp_num;
        }
        else {
            sum_1 += (arr[i] * 2);
        }
    }

    // sum for digits in between
    for (int j = 1; j < l; j += 2) {
        sum_2 += arr[j];
    }

    //validating the card num
    total = sum_1 + sum_2;

    if (total % 10 == 0 && arr[0] == 3 && l == 15) {
        printf("VAILD!\nCARD TYPE: AMEX\n");
    }
    if (total % 10 == 0 && arr[0] == 4) {
        printf("VAILD!\nCARD TYPE: VISA\n");
    }
    if (total % 10 == 0 && arr[0] == 5 && l == 16) {
        printf("VAILD!\nCARD TYPE: MASTERCARD\n");
    }
    else {
        printf("INVAILD CARD!\n");
    }

}


int len(long long length)
{
    // calculating the len of the integar
    int count = 0;
    int len = 0;
    while (length > 10) {
        length = length / 10;
        count += 1;
    }
    len = count + 1;
    return len;
}


int split_sum(int num)
{
    // make a function for spliting into digits and sum
            int temp = 0;
            int temp_sum = 0;
            temp += (num * 2);
            int len_temp = len(temp);

            int arr[2] = {};
            int last_digit = temp % 10;
            int sec_last_digit = temp / 10;
            arr[0] = sec_last_digit;
            arr[1] = last_digit;

                for (int x = 0; x < len_temp; x++){
                    temp_sum += arr[x];
                }
            return temp_sum;
}
