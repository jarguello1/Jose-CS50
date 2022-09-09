from cs50 import get_int

# TODO

while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

i = 1
while i <= n:

    # spaces before the blocks to make them even
    print(" " * (n - i), end="")

    # left blocks
    print("#" * i, end="")

    # middle gap
    print("  ", end="")

    # right blocks
    print("#" * i, end="")

    # move to next row
    print()

    i += 1