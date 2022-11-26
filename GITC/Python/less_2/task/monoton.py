heights = list(map(int,input('seq ').split()))
asc = 0
dsc = 0
no = 0
temp = heights[0]

for iterator in range(1,len(heights)):
    if heights[iterator] > temp:
        asc += 1
    elif heights[iterator] < temp:
        dsc += 1
    else:
        no += 1
    temp = heights[iterator]

if dsc == 0 and no == 0:
    print("ASC")
elif asc == 0 and no == 0:
    print("DSC")
else:
    print("NOT")