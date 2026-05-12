question = input("What is the answer to the Great Question of Life, the Universe, and Everything?")

question = question.replace(" ", "")

if question == "42":
    print("Yes")
elif question.lower() == "forty-two":
    print("Yes")
elif question.lower() == "fortytwo":
    print("Yes")
else:
    print("No")
