original = input("Input: ")

output = ""

for c in original:
    if (c != 'a' and c != 'e'
    and c != 'i' and c != 'o'
    and c != 'u' and c != 'A'
    and c != 'E' and c != 'I'
    and c != 'O' and c != 'U'):
        output = output + c

print("Output:", output)
