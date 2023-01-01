numA = input("enter the number ") #mutqagrenq tiv@
listA = list(map(int,numA)) #sarkenq interi list
listA.sort(reverse = True) #mer list@ sortavorenq @st nvazman
#print(listA)
numB = str(listA[0]) #listi araji element@ qcenq stringi mej
for i in listA[1::1]: 
    numB += str(i) #hertov mnacacner@ dabavka enenq
#print(numB)
if numB > numA:  #hamematenq 2 stringner@ chnayac krnainq inti bereinq nor hamemateinq
    print("YES") #irevi interov aveli arag kexni
else:
    print("NO")