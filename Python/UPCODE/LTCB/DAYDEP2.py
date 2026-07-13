total = 0

while (True):
    try:
        num = int(input())
        total += num
        if (num == 0): break
    except: break

if (total % 100 == 0): 
    print("DEP")
elif (total % 100 == 55):
    print("TRUNGBINH")
else:
    print("XAU")