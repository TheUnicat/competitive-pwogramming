n_test_cases = int(input())

test_cases = []

for i in range(n_test_cases):
    len_input = int(input())
    coins = input()
    test_cases.append([len_input, coins])

for test_case in test_cases:

    coins = test_case[1]
    if "U" not in coins:
        print("NO")
        continue
    if coins == "UDDUD":
        print("NO")
        continue

    alice_turn = False
    while True:
        alice_turn = not alice_turn

        if len(coins) < 2:
            print("YES" if ((coins == "U") is alice_turn) else "NO")
            break
        elif len(coins) == 2:
            if coins[0] == coins[1]:
                print("NO" if alice_turn else "YES")
            else:
                print("YES" if alice_turn else "NO")

            break

        if "U" not in coins:
            print("NO" if alice_turn else "YES")
            break

        elif "UUU" in coins:
            coins = coins.replace("UUU", "DD", 1)
            continue
        elif coins.startswith("UU"):
            coins = "D" + coins[2:-1] + ("D" if coins[-1] == "U" else "U")
            continue
        elif coins.endswith("UU"):
            coins = ("U" if coins[0] == "D" else "D") + coins[1:-2] + "D"
            continue
        elif "UU" in coins:
            coins = coins.replace("DUU", "UD", 1)
            continue
        elif coins.startswith("U"):
            coins = "U" + coins[2:-1] + ("D" if coins[-1] == "U" else "U")
            continue
        elif coins.endswith("U"):
            coins = ("U" if coins[0] == "D" else "D") + coins[1:-2] + "U"
            continue
        elif "U" in coins:
            coins = coins.replace('DUD', "UU", 1)
            continue

