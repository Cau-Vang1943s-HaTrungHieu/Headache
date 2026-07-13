def unique_vals(lst):
    result = []
    for val in lst:
        if val not in result:
            result.append(val)
    return result

n = int(input())
lst = []
for i in range(n):
    lst.append(int(input()))
print(unique_vals(lst))