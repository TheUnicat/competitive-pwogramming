n_test_cases = int(input())

test_cases = []

for i in range(n_test_cases):
    case_length = int(input())
    a = [int(num) for num in input().split()]
    b = [int(num) for num in input().split()]

    test_cases.append([a, b])


for test_case in test_cases:
    a, b = test_case[0], test_case[1]
    count = 0


    while True:
        can_stop = True
        for i in range(len(a)):
            a_value = a[i]
            b_value = b[i]

            if a_value > b_value:
                can_stop = False
                a.insert(0, 1)
                a.pop(-1)
                count += 1

        if can_stop:
            break

    print(count)



