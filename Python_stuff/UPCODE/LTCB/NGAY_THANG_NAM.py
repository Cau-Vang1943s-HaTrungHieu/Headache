day, month, year = map(int, input().split())

if year >= 1900:
    if month >= 1 and month <= 12 and day >= 1:
        match month:
            case 1 | 3 | 5 | 7 | 8 | 10 | 12:
                if day <= 31: print("YES")
                else: print("NO")
            case 4 | 6 | 9 | 11:
                if day <= 30: print("YES")
                else: print("NO")
            case 2:
                if ((year % 4 == 0) and (year % 100 != 0 or year % 400 == 0)):
                    if day <= 29: print("YES")
                elif day <= 28: print("YES")
                else: print("NO")
            case _: pass
else: print("NO")