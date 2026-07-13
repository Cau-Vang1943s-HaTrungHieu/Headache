import sys

for line in sys.stdin:
    line = line.strip() 
    if line.isdigit():
        digit_sum = sum (int(char) for char in line)
        print(digit_sum)

# "Thorough explanation"
"""
for line in sys.stdin:
- This loop reads each line of input from user until they Ctrl Z
line = line.strip()
- This expression removes any extra spaces or newline characters,
ensuring there isn't anything like "\n" or space disrupting the
checking

from the beginning and end of the line
line.isdigit()
- Checks if the line contains only digits

digit_sum = sum(int(char) for char in line)
(Below is the execution order)
- for char in line  --> "For each character in a line"
- int(char)         --> "convert them into integer"
- sum()             -->  "Calculate their sum"

Then print()

"""