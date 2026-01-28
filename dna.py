import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Incorrect command-line usage")
        sys.exit(1)

    # Read database file into a variable
    csv_file = sys.argv[1]
    rows = []
    with open(csv_file) as file:
        name = csv.DictReader(file)
        for row in name:
            rows.append(row)

    # Read DNA sequence file into a variable
    text_file = sys.argv[2]
    with open(text_file) as file:
        dna_sequence = file.read()

    # Find longest match of each STR in DNA sequence
    longest_matches = {}

    rows_len = len(rows)

    for i in rows[0]:
        longest_matches[i] = longest_match(dna_sequence, i)

    # Check database for matching profiles
    number_of_same_sequences = 0

    for i in range(rows_len):
        for j in longest_matches:
            if str(longest_matches[j]) == rows[i][j]:
                number_of_same_sequences += 1

        if number_of_same_sequences == len(longest_matches) - 1:
            print(rows[i]['name'])
            break
        else:
            number_of_same_sequences = 0

    if number_of_same_sequences != len(longest_matches) - 1:
        print('No match')

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

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
