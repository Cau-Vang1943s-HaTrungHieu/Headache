# Circumference of a circle = 2 * Pi * radius = diameter * Pi

import math

Pi = math.pi
radius = float(input("Input the radius of your circle: "))
Circumference = 2 * Pi * radius
print(f"Circumference of a circle is {round(Circumference, 2)}")