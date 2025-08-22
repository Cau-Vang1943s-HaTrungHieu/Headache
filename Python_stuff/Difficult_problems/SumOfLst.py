def sum_of_list(lst):
    result = 0
    for val in lst:
        result += val
    return result

lst = []
n = int(input())
for i in range(n):
    lst.append(int(input()))
print(sum_of_list(lst))
