my_list = list(map(int, input().split()))

if (len(my_list) < 3):
    print("NO")
else:
    print(len(my_list))
    print(sum(my_list))
    my_list.sort()
    print(*my_list)