from cs50 import get_int

height = get_int("Height: ")

while height < 1 or height > 8:
    height = get_int("Height: ")

for _ in range(height):

    for a in range(height - _ - 1):
        print(' ', end="")

    for b in range(_ + 1):
        print('#', end="")

    for c in range(2):
        print(' ', end="")

    for d in range(_ + 1):
        print('#', end="")

    print('\n', end="")
