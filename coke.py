change_owed = 50
print("Amount Due: 50")

while change_owed > 0:
    coin = int(input("Insert Coin: "))
    if coin == 25 or coin == 10 or coin == 5:
        change_owed = change_owed - coin
    if change_owed > 0:
        print("Amount Due:", change_owed)

print("Change Owed:", -change_owed)
