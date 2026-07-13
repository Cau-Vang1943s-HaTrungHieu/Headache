myList = []

while (True):
    try:
        a = int(input())
        if (a == 0): break
        myList.append(a)
    except:
        break
print(myList)