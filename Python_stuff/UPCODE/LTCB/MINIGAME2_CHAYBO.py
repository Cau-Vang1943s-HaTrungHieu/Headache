ab, bc, ca = map(int, input().split())
t = int(input())



if (t > (ab + bc + ca)):
    t %= (ab + bc + ca)

if (t <= ab):
    if (t == 0): print('A')
    elif (t == ab): print("B")
    else: print("AB")
elif (t <= bc + ab):
    if (t == bc + ab): print("C")
    else: print("BC")
elif (t <= ca + bc + ab):
    if (t == ca + bc + ab): print("A")
    else: print("CA") 