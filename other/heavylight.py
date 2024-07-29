alphabet = [char for char in 'abcdefghijklmnopqrstuvwxyz']

stats = input().split()

n_strings = int(stats[0])
len_string = int(stats[1])

stringies = []

for i in range(n_strings):
    stringies.append(input())

for string in stringies:
    broken_string = [char for char in string]
    is_heavy = {}
    for char in alphabet:
        if char in broken_string:
            broken_string.remove(char)
            if char in broken_string:
                is_heavy[char] = True
            else:
                is_heavy[char] = False
        else:
            is_heavy[char] = False

    first_string = True
    last_char_heavy = False
    is_char_heavy = False
    is_correct = True
    for char in string:
        if first_string:
            first_string = False
            is_char_heavy = is_heavy[char]
        else:
            last_char_heavy = is_char_heavy

            is_char_heavy = is_heavy[char]

            if last_char_heavy is is_char_heavy:
                 print("F")
                 is_correct = False
                 break

    if is_correct:
        print("T")
