import math

a = int(input())
b = int(input())

if (a == 0): 
    if (b == 0): print("VSN")
    else: print("VN")
else: 
    result = -b / a
    rounded = math.ceil(result * 100) / 100 # round up to 2 decimal places
    print(f"{rounded: .2f}")