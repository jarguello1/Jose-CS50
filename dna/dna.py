import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Missing command-line arguments")
        sys.exit(1)

    # TODO: Read database file into a variable
    with open(sys.argv[1]) as db_file:
        reader = csv.DictReader(db_file)
        database = list(reader)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as file:
        dna_sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    matches = {}

    # This results in "name" being index [0]
    for i in database[0]:
        matches[i] = (longest_match(dna_sequence, i))

    # TODO: Check database for matching profiles
    person = 'No Match'
    person_counter = 1

    for i in range(len(database)):
        for j in matches:
            # Matches values are ints, need to cast them to string for comparsion
            if str(matches[j]) == database[i][j]:
                person_counter += 1
        if person_counter == len(matches):
            person = database[i]['name']
            break
        else:
            person_counter = 1

    print(person)

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()