def convert(original):
    converted = original.replace(":)", "🙂")
    converted = converted.replace(":(", "🙁")
    return converted

def main():
    original = input('')
    converted = convert(original)
    print(converted)

main()
