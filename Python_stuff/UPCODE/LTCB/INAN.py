import math

type, pages, copies = map(int, input().split())

if (type == 1):
    print(pages * copies)
elif (type == 2):
    sheets = math.ceil(((pages + 1) // 2) * copies)
    print(sheets)