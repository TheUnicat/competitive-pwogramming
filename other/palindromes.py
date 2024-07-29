number_of_palindromes = int(input())


testcases = []

for i in range(number_of_palindromes):
    testcases.append(input())


for testcase in testcases:
    length = len(testcase)

    if True:
        is_palindrome = True
        for i in range(int(length / 2)):
            if testcase[i] != testcase[length - i - 1]:
                print("NO")
                is_palindrome = False
                break
        if is_palindrome:
            print("YES")