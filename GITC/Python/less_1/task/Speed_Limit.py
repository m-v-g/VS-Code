point = 9.0
speed = int(input("Enter the speed "))
if speed <= 70:
    print("OK")
elif speed > 70 and speed <= 80:
    print("Amount of the fine: " + str((speed - 70) * 1000) + " Points left: " + str(point))
elif speed > 80 and speed <= 100:
    print("Amount of the fine: 20000 Points left: " + str(point - 2))
elif speed > 100 and speed <= 120:
    print("Amount of the fine: 25000 Points left: " + str(point - 3))
elif speed > 120 and speed <= 150:
    print("Amount of the fine: 29000 Points left: " + str(point - 4))
else:
    print("Amount of the fine: 200000 And license suspended for 1 year")