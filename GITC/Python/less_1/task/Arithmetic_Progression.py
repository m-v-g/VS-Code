a = int(input("type A "))
b = int(input("type B "))
n = int(input("type N "))
a = b - a
m = 2
while m < n:
    b += a
    m += 1
print(str(n) + " th member of the sequence " + str(b))