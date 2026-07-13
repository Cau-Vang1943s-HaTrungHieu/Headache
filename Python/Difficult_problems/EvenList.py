def evenNums(lst):
    result = []
    for val in lst:
        if (val not in result and val % 2 == 0):
            result.append(val)
    return result


res = []
length = int(input())
for i in range(length):
    res.append(int(input()))

print(evenNums(res))
