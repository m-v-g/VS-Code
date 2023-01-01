def binary_search(list, item): #v peremennoy low i high xranyatsya
    low = 0                    #granici toy chasti spiska v kotoroy
    high = len(list)-1         #vipolnyaetsya poisk

    while low <= high:         #poka eta chast spiska ne sokratitsya do odnogo elementa
        mid = (low + high)     #proveryaem sredny element
        guess = list[mid]
        if guess == item:      #znachenie naideno
            return mid
        if guess > item:       #mnogo
            high = mid - 1
        else:                  #malo
            low = mid + 1
    return None                #znachenie ne sushestvuet

my_list = [1, 3, 5, 7, 9]

print (binary_search(my_list, 3)) # => 1
print (binary_search(my_list, -1)) # => None