def foo(myList, myString):
    for i in myString:
        for j in myList:
            if i == j:
                myList.remove(j)
                break
    
myList = ['s', 't', 'r', 'i', 'n', 'g']
myString = "string"
foo(myList, myString)
print(myList)