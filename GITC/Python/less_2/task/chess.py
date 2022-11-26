heights = list(map(int,input('height').split())) #
maximum = 0
result = 0
for iterator in heights:
    if iterator > maximum:
        maximum = iterator
for iterator in heights:
    result += (maximum - iterator)
print(f'your result is {result}')

"""
this is
a long comment
block
"""