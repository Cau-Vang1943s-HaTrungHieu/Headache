def charEvaluation(s):
    upperCases = 0
    lowerCases = 0
    for char in s:
        if char.isupper(): upperCases += 1
        if char.islower(): lowerCases += 1
    print("Given string:", s)
    print("Number of uppercase letters:", str(upperCases))
    print("Number of lowercase letters:", str(lowerCases))            

s = input()
charEvaluation(s)
