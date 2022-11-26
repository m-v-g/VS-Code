import random

def foo():
    inList = list(map(int,input("input your 4 digit number: ")))
    for i in range(0,4):
        if randList[i] == inList[i]: #ete chotki gtel enq
            outList[i] = 'R'
        else:
            if inList[i] in randList: #ete gtel enq bayc urish tex
                outList[i] = 'Y'
            else: #ete chenq gte
                outList[i] = 'B'
    #print(outList)

randList = [random.randint(0,9)] #sarkenq list@ u grenq araji element@
for i in range(1,4):
    randList.append(random.randint(0,9)) #forov grenq myus 3 elementner@

print(randList)

inList = [-1, -1, -1, -1]
outList = ['O', 'O', 'O', 'O']
it = 0 #kyanqeri qanak

for it in range(0,10):
    if outList != ['R', 'R', 'R', 'R']:
        foo()
    else:
        break #ete arden gtel enq el kariq chka sax cikl@ fralu
    print("LIFE LEFT = " + str(9 - it))
    it += 1

if outList == ['R', 'R', 'R', 'R']:
    print("BINGO " + str(randList))
else:
    print("GAME OWER")
input("press any key to exit")