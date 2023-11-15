# TODO
def count_letters(s):
    count = 0
    for i in s:
        if i.isalpha():
            count += 1
    return count


def count_words(s):
    count = 1
    for i in s:
        if i == " ":
            count += 1
    return count


def count_sentences(s):
    count = 0
    for i in s:
        if i == "." or i == "!" or i == "?":
            count += 1
    return count


string = input("Text: ")
while len(string) < 1:
    string = input("Text: ")

letters = count_letters(string)
words = count_words(string)
sentences = count_sentences(string)

L = round((letters / words * 100), 4)
S = round((sentences / words * 100), 4)
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade " + str(index))
