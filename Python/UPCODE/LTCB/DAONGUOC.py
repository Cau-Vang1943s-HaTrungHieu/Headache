num = int(input())

print(str(int(num % 10)) + '' + str(int(num / 10 % 10)) + '' + str(int(num / 100)))

''' More efficient way
# Nhập vào một số có 3 chữ số dưới dạng chuỗi
number = input("Nhập số có 3 chữ số: ")

# Đảo ngược chuỗi và in ra kết quả
print(number[::-1])

'''