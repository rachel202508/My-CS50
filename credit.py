from cs50 import get_int


def main():
    number = get_int("Number: ")

    sum = calculate_sum(number)

    number_of_digits = calculate_number_of_digits(number)

    check_validity(number, number_of_digits, sum)


def calculate_sum(number):

    number_of_digits = 1
    sum = 0

    while number > 0:
        if number_of_digits % 2 == 0:
            digit = (number % 10) * 2
            number = number // 10
            number_of_digits += 1
            if digit >= 10:
                digit = digit % 10
                sum += digit
                sum += 1
            else:
                sum += digit

        elif number_of_digits % 2 == 1:
            digit = number % 10
            sum += digit
            number = number // 10
            number_of_digits += 1

    number_of_digits -= 1

    return sum


def calculate_number_of_digits(number):
    number_of_digits = 0
    while number > 0:
        number = number // 10
        number_of_digits += 1

    return number_of_digits


def check_validity(number, number_of_digits, sum):
    if sum % 10 == 0:

        if ((number_of_digits == 13) and (number // 1000000000000 == 4)):
            print("VISA")

        elif ((number_of_digits == 15) and
              ((number // 10000000000000 == 34) or (number // 10000000000000 == 37))):
            print("AMEX")

        elif number_of_digits == 16:

            if number // 1000000000000000 == 4:
                print("VISA")

            elif ((number // 100000000000000 == 51) or (number // 100000000000000 == 52) or
                  (number // 100000000000000 == 53) or (number // 100000000000000 == 54) or
                  (number // 100000000000000 == 55)):
                print("MASTERCARD")

            else:
                print("INVALID")

        else:
            print("INVALID")

    else:
        print("INVALID")


main()
