num = input("enter the number")
kent = 0
zuyg = 0
for x in range(len(num),-1):
    if x % 2 == 0:
        zuyg += int(num[x])
    else:
        kent += int(num[x])
if kent == zuyg:
    print("YES")
else:
    print("no")