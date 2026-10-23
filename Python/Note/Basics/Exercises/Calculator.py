# Python calculator

operator = input("Enter an operator: ")
operand1 = float(input("Enter the first operand: "))
operand2 = float(input("Enter the second operand: "))

if operator == '+':
    result = operand1 + operand2
elif operator == '-':
    result = operand1 - operand2
elif operator == '*':
    result = operand1 * operand2
elif operator == '/':
    result = operand1 / operand2
else:
    print(f"Are you dumb or something? {operator} is not a valid here")

print(round(result, 2))