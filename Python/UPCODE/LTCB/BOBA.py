n, m, k = map(int, input().split())

n_digits = [int(char) for char in str(n)]
n_sumOfDigits = sum(n_digits)

while (m > 10):
    m //= 10
else:
    m_firstChar = m

print ("Yes") if (n_sumOfDigits + m_firstChar == k) else print("No")