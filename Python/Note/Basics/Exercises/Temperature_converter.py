# C --> F: (C_Degree * 9/5) + 32 = F_Deg
# F --> C: (F_Deg - 32) * 5/9 = C_Deg

unit = input("Celsius or Fahrenheit (C/F): ")
temp = float(input("Enter temperature: "))

if unit == "C":
    temp = (temp * 9) / 5 + 32
    print(f"The temperature in Fahrenheit is {round(temp, 1)} Fahrenheit")
elif unit == "F":
    temp = (temp - 32) * 5 / 9
    print(f"The temperature in Celsius is {round(temp, 1)} Celsius")
else:
    print(f"What the fuck is {unit}?")
