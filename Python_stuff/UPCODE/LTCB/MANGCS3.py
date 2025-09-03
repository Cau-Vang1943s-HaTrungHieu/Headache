remove_index = int(input())
my_list = list(map(int, input().split()))
my_list.pop(2)
print(*my_list) # asterisk here means unpacking method