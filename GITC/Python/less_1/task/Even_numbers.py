t = True
while t:
    a = int(input("type A "))
    b = int(input("type B "))
    if a < b:
        t = False
while a <= b:
    if a % 2 == 0:
        print(a)
    a += 1