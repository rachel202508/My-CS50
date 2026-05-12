expression = input("Expression: ")

x, y, z = expression.split(" ")

x = float(x)
z = float(z)

if y == '+':
    output = float(x + z)
elif y == '-':
    output = float(x - z)
elif y == '*':
    output = float(x * z)
elif y == '/' and z != 0:
    output = float(x / z)

print(f"{output:.1f}")
