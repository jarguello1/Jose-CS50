# TODO

import string


def main():

    # Prompt user for Text to examine
    text = input("Text: ")

    # Count the number of words in the text
    words = count_words(text)

    # Count the number of sentences in the text
    sentences = count_sentences(text, words)

    # Count the number of letters in the text
    letters = count_letters(text, words)

    # Calculate using Coleman-Liau index
    # CL_index = 0.0588 * L - 0.296 * S - 15.8
    grade_level = (0.0588 * letters) - (0.296 * sentences) - 15.8
    rounded_grade = round(grade_level)

    if rounded_grade < 1:
        print("Before Grade 1")
    elif rounded_grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade {rounded_grade}")


# count words in the string
def count_words(text):
    return len(text.split())


# count sentences in a string and divide by number of words
def count_sentences(text, words):
    sentence_count = 0
    for i in text:
        if i in "!.?":
            sentence_count += 1
    average_sentences = sentence_count / words * 100
    return average_sentences


# count letters in a string and divide by number of words
def count_letters(text, words):
    letter_count = 0
    for i in text:
        if i in string.ascii_letters:
            letter_count += 1
    average_letters = letter_count / words * 100
    return average_letters


main()