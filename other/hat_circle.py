n_people = input()
numbers = []

for i in range(int(n_people)):
    numbers.append(int(input()))

same_numbers = 0

for i in range(int(len(numbers)/2) if len(numbers) % 2 == 0 else int(len(numbers)/2) + 1):
    if numbers[i] == numbers[i + int(len(numbers)/2)]:
        same_numbers += 2

print(same_numbers)