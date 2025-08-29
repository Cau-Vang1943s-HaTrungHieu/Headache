import sys

myList = []
for line in sys.stdin:
    line = line.strip()
    if line.isdigit():
        myList.append(int(line))

print(myList)

"""
line can be assigned to a variable
"""