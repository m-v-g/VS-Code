def zibil():
    for it in directionIn:
        if it != ['n', 'w', 's', 'e']:
            directionIn.remove(it)

def uborka():
    for it in range(0,len(directionIn)):
        if it != 0:
            if directionIn[it] == 'n' and directionIn[it - 1] == 's':
                directionIn[it] = 'o'
                directionIn[it - 1] = 'o'
            elif directionIn[it] == 's' and directionIn[it - 1] == 'n':
                directionIn[it] = 'o'
                directionIn[it - 1] = 'o'
            elif directionIn[it] == 'w' and directionIn[it - 1] == 'e':
                directionIn[it] = 'o'
                directionIn[it - 1] = 'o'
            elif directionIn[it] == 'e' and directionIn[it - 1] == 'w':
                directionIn[it] = 'o'
                directionIn[it - 1] = 'o'

directionIn = list(map(str,input('input dhe direction ').split()))
print(directionIn)
uborka()
print(directionIn)
zibil()
print(directionIn)