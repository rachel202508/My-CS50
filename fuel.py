while True:

    try:
        fraction = input("Fraction: ")
        x, y = fraction.split("/")
        x = int(x)
        y = int(y)

        percent = round(float(x / y) * 100)

        if (percent < 0 or percent > 100):
            pass
        elif (not isinstance(x, int)) or (not isinstance(y, int)):
            pass
        else:
            if percent <= 1:
                print("E")
            elif percent >= 99:
                print("F")
            else:
                print(percent, "%", sep="")
            break

    except (ValueError, ZeroDivisionError, TypeError):
        pass

