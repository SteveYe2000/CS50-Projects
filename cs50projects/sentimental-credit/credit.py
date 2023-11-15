# TODO
n = input("Number: ")
while len(n) < 9 or len(n) > 17:
    n = input("Number: ")

card_num = []
l = len(n)
for i in n:
    card_num.append(int(i))

sum_1 = []
sum_2 = []

if l % 2 != 0:
    for j in range(1, l, 2):
        sum_1.append(card_num[j]*2)
    for z in range(0, l, 2):
        sum_2.append(card_num[z])
else:
    for s in range(0, l, 2):
        sum_1.append(card_num[s]*2)
    for q in range(1, l, 2):
        sum_2.append(card_num[q])

for x in range(0, len(sum_1)):
    if sum_1[x] > 9:
        remainder = sum_1[x] % 10
        divisor = sum_1[x] // 10
        splited = remainder + divisor
        sum_1[x] = splited

total = sum(sum_2) + sum(sum_1)

if total % 10 == 0 and l == 15 and card_num[0] == 3 or card_num[1] == 4 or card_num[1] == 7:
    print("AMEX")
if total % 10 == 0 and card_num[0] == 4 and l == 16 or l == 13:
    print("VISA")
if total % 10 == 0 and l == 16 and card_num[0] == 5:
    if card_num[1] == 1 or card_num[1] == 2 or card_num[1] == 3 or card_num[1] == 4 or card_num[1] == 5:
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")
