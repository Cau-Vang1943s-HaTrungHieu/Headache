hour = int(input())
min = int(input())
sec = int(input())

if (0 <= hour < 24 and 0 <= min < 60 and 0 <= sec < 60):
    print("YES")
    sec += 1
    if (sec == 60):
        sec = 0
        min  += 1
        if (min == 60):
            min = 0
            hour += 1
            if (hour == 24):
                hour = 0
    print(f"{hour}:{min}:{sec}")
else:
    print("NO")