num = int(input("enter the number"))
div = 0
for x in range(1,num + 1):
    if num % x == 0:
        div += 1
print("division count" + str(div))