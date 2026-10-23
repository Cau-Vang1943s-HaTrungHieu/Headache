item = input("What did you buy?: ")
price = float(input("What is the cost of the item?: "))
quantity = int(input("How many would you like to buy?: "))

total_cost = price * quantity
print(f"You have bought {quantity} {item}(s) with {total_cost}.")