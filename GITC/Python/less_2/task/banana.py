bar = input("say word in upper ")
vowels = ["A", "E", "O", "U", "I"]
bax = 0
dzay = 0
for i in range(len(bar)):
    for j in vowels:
        if bar[i] == j:
            dzay += 1
            iterator = i + 1
            while iterator < len(bar):
                dzay += 1
                iterator += 1
        else:
            bax += 1
            iterator = i + 1
            while iterator < len(bar):
                bax += 1
                iterator += 1
print("bax = " + str(bax))
print("dzay = " + str(dzay))