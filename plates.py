def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    if (is_length(s) and check_punctuation(s)
        and start_with(s) and position_of_numbers(s)):
        return True
    return False


def start_with(s):
    if not is_length(s):
        return False
    if s[0].isalpha() and s[1].isalpha():
        return True
    return False


def is_length(s):
    if 2 <= len(s) <= 6:
        return True
    return False


def position_of_numbers(s):
    if not is_length(s):
        return False
    l = len(s)

    for c in range(2, l):
        if s[c].isdigit():
            if s[c] == '0':
                return False
            elif not s[slice(c, l)].isdigit():
                return False
            return True
    return True


def check_punctuation(s):
    if not is_length(s):
        return False
    if ((" " in s) or ("," in s)
        or ("." in s) or (":" in s)
        or (";" in s) or ("''" in s)
        or ("?" in s) or ("!" in s)):
        return False
    return True


main()
