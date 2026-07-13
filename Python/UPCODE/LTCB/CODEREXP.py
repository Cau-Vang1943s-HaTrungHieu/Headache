basic, medium, advanced, hard = map(int, input().split())

exp = basic * 10 + medium * 20 + advanced * 30 + hard * 40

print(exp)

if (exp == 0): print("Coder So Sinh")
elif (exp >= 1 and exp <= 49): print("Coder Lop Mam")
elif (exp >= 50 and exp <= 99): print("Coder Lop Chuoi")
elif (exp >= 100 and exp <= 499): print("Coder Lop La")
elif (exp >= 500 and exp <= 999): print("Coder Tieu Hoc")
elif (exp >= 1000 and exp <= 1499): print("Coder THCS")
elif (exp >= 1500 and exp <= 1999): print("Coder THPT")
elif (exp >= 2000 and exp <= 2499): print("Coder Trung Cap")
elif (exp >= 2500 and exp <= 3499): print("Coder Cao Dang")
elif (exp >= 3500 and exp <= 4199): print("Coder Dai Hoc")
elif (exp >= 4200 and exp <= 5499): print("Coder Thac Si")
elif (exp >= 5500 and exp <= 6999): print("Coder Tien Si")
else: print("Coder Giao Su")