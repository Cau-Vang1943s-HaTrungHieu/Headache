num = int(input())

if (num < 1000): 
    print(-1)
else:
    print(int(num / 1000 % 10))