redundant = int(input())
intVals = list(map(int, input().split()))
positiveVals = [value for value in intVals if value > 0]
negativeVals = [value for value in intVals if value < 0]
print(*negativeVals)
print(*positiveVals)