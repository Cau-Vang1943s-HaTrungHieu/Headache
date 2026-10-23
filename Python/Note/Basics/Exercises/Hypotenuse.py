import math

# Given a triangle with 3 edges a, b, c in which c is the hypotenuse.
a = float(input("Input a: "))
b = float(input("Input b: "))

hypotenuse = math.sqrt(pow(a, 2) + pow(b, 2))
print(f"The hypotenuse of your triangle is {round(hypotenuse, 2)}")