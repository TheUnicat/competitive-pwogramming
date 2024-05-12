params = input()

N, M = int(params.split()[0]), int(params.split()[1])

def n_deranged(value):
    if value == 1:
        return 0
    elif value == 2:
        return 1
    elif value == 3:
        return 2
    else:
        return (value - 1)*(n_deranged(value - 1) + n_deranged(value - 2))

results = [str(n_deranged(i) % M) for i in range(1, N + 1)]

print(" ".join(results))