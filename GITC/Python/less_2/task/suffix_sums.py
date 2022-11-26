listA = list(map(float,input('type the sequance ').split()))
listB = [0.0]
temp = 0.0
for iterator in listA[::-1]:
    temp = temp + iterator
    #print(temp)
    listB.append(temp)
listB.remove(0)
for iterator in listB:
    print(iterator)