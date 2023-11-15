# TODO
height = input("Height: ")

while height.isdigit() != True or int(height) < 1 or int(height) > 8:
    height = input("Height: ")
else:
    h = int(height)

for i in range(1, h+1):
    for j in range(h, 0, -1):
        if j > i:
            print(" ", end="")
        else:
            print("#", end="")
    print()
