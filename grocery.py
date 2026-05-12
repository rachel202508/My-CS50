list = {}

while True:
    try:
        item = (input("")).upper()
        if item in list:
            list[item] += 1
        else:
            list[item] = 1

    except KeyError:
        break

    except EOFError:
        print("")
        list = dict(sorted(list.items()))
        for c in list:
            print(list[c], c)
        break
