#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_letters(string input);
int count_words(string input);
int count_sentences(string input);

int main(void)
{
    // getting user input
    string text = get_string("Text: ");
    int len_text = strlen(text);
    while (len_text < 1) {
        text = get_string("Text: ");
        len_text = strlen(text);
    }

    // important variables
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // calulating L
    float L = ((float) letters / (float) words) * 100;

    //calculating S
    float S = ((float) sentences/ (float) words) * 100;

    // calculating grade
    int index = 0.0588 * L - 0.296 * S - 15.8;

    // indicate grade
    if (index < 1) {
        printf("Before Grade 1\n");
    }
    else {
        if (index >= 16) {
            printf("Grade: 16+\n");
        }
        else {
            printf("Grade: %i\n", index);
        }
    }

}


int count_letters(string input)
{
    int counter = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            counter += 1;
        }
    }
    return counter;
}


int count_words(string input)
{
    int counter = 1;
    for (int i = 0; i < strlen(input); i++) {
        if (isblank(input[i])) {
            counter += 1;
        }
    }
    return counter;
}


int count_sentences(string input)
{
    int counter = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (ispunct(input[i])) {
            counter += 0;
        }
        if (input[i] == '.' || input[i] == '!') {
            counter += 1;
        }
    }
    return counter;
}
