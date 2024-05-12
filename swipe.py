n_length = int(input())

A = input()
B = input()

array_A = [int(num) for num in A.split()]

array_B = [int(num) for num in B.split()]

left_swipes = []
right_swipes = []



for i in range(n_length):
    A_value = array_A[i]
    for j in range(i + 1, n_length):
        B_value = array_B[j]

        if j == n_length - 1:
            if A_value == B_value:
                if j > i:
                    right_swipes.append(f"R {i} {j}")
            if j > (i + 1):
                right_swipes.append(f"R {i} {j - 1}")
            break
        if B_value != A_value:
            if j > (i + 1):
                right_swipes.append(f"R {i} {j - 1}")
            break

for i_initial in range(n_length):
    i = n_length - 1 - i_initial
    A_value = array_A[i]
    for j_initial in range(1, i + 1):
        j = i - j_initial
        B_value = array_B[j]

        if j == 0:
            if A_value == B_value:
                if j < i:
                    left_swipes.append(f"L 0 {i}")
            elif j < (i - 1):
                left_swipes.append(f"L 1 {i}")
            break

        if B_value != A_value:
            if j < (i - 1):
                left_swipes.append(f"L {j + 1} {i}")
            break


reversed_right_swipes = []
for swipe in right_swipes:
    reversed_right_swipes.insert(0, swipe)

reversed_left_swipes = []
for swipe in left_swipes:
    reversed_left_swipes.insert(0, swipe)

for swipe in reversed_left_swipes:
    i = int(swipe.split()[1])
    j = int(swipe.split()[2])

    value = array_A[j]
    for k in range(i, j):
        array_A[k] = value

for swipe in reversed_right_swipes:
    i = int(swipe.split()[1])
    j = int(swipe.split()[2])

    value = array_A[i]
    for k in range(i + 1, j + 1):
        array_A[k] = value

if array_A == array_B:
    print("YES")
    print(len(left_swipes) + len(right_swipes))
    for swipe in reversed_left_swipes:
        print(swipe)
    for swipe in reversed_right_swipes:
        print(swipe)
else:
    print("NO")

