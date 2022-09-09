# TODO

def main():
    # While the input isnt a number positive number request a number
    while True:
        try:
            number = int(input("Number: "))
            if number > 0:
                break
        # Any other input other than an integer has error raised with instructions
        except ValueError:
            print("That is not a credit card number,")
    checksum(number)


def checksum(number):
    # Add each number as a seperate index to a list
    card_numbers = [int(s) for s in list(str(number))]
    # From the 2nd to last number going backwards take every other number and add it to a list
    odd_numbers = card_numbers[::-2]
    # From the last number going backwards take every other number and add it to a list
    even_numbers = card_numbers[-2::-2]
    # Value for the total sum
    total = 0
    odd_total = sum(odd_numbers)
    even_total = []
    # For every number in the even number list, double the the number.
    # If they're higher than 10, subtract by 9 to get the sum of the tens and ones place digits
    for i in even_numbers:
        i *= 2
        if i > 9:
            even_total.append(i-9)
        elif i <= 9:
            even_total.append(i)
    total = odd_total + sum(even_total)

    # If the sum of the values isn't remainder 10, return invalid. Otherwise run verify_card function
    if total % 10 != 0:
        print("INVALID")
    else:
        verify_card(number)


def verify_card(number):
    # Second list for each value in the card number
    verified_number = [int(s) for s in list(str(number))]
    # Take the first to values from the verified_number list and add them together
    start_number = verified_number[0]*10 + verified_number[1]
    # Conditionals for each card
    if (len(verified_number) == 13 or len(verified_number) == 16) and (start_number > 39 and start_number < 50):
        print("VISA")
    elif (len(verified_number) == 16) and (start_number > 50 and start_number < 56):
        print("MASTERCARD")
    elif (len(verified_number) == 15) and (start_number == 34 or start_number == 37):
        print("AMEX")
    elif (len(verified_number) != 15 and len(verified_number) != 16 and len(verified_number) != 13):
        print("INVALID wrong length")
    else:
        print("INVALID")


main()