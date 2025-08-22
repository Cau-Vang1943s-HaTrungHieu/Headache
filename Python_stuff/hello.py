import math

t, p, c = map(int, input().split())

if (t == 1): 
    print(p * c)
else:
    print(math.ceil(p/2 * c))