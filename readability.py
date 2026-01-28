from cs50 import get_string


def main():
    text = get_string("Text: ")

    letters = calculate_letters(text)
    words = calculate_words(text)
    sentences = calculate_sentences(text)

    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


def calculate_letters(text):

    l = len(text)
    number_of_letters = 0

    for i in range(l):
        if (text[i].isupper() or text[i].islower()):
            number_of_letters += 1

    return number_of_letters


def calculate_words(text):

    l = len(text)
    number_of_words = 1

    for _ in range(l):
        if text[_] == ' ':
            number_of_words += 1

    return number_of_words


def calculate_sentences(text):

    l = len(text)
    number_of_sentences = 0

    for _ in range(l):
        if (text[_] == '!' or text[_] == '?' or text[_] == '.'):
            number_of_sentences += 1

    return number_of_sentences


main()
