n_test_cases = int(input())
test_cases = []

for i in range(n_test_cases):
    params = input().split()
    n = int(params[0])
    coins = int(params[1])

    counts = input().split()

    numbers = []
    for i in range(n):
