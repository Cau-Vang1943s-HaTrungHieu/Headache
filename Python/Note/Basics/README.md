# Some notices when you first encounter a python

## Python Interpreter

- A thing that converts our written code to machine code.
- [Download here](https://www.python.org/)

## Basic things

Expression: A piece of syntax that can be evaluated to some value. For example: 5 + 5 is an expression  
Logica
As a beginner, you could use these common python commands:  

- [Common_statements](Common_statements.md)
- []

## Variables and datatypes

- Just like C++, Python has a container which could be of type int, [string](Python_string.md), float, and boolean.
- Unlike C++ or C, a variable's datatype doesn't need to be declared beforehands. The variable is bound to the type of the data assigned to it.
- Notice that Python doesn't have `char` type like C/C++

For example:

```python
first_name = "Hieu"
age = 21
is_student = True # Remember, captital T
print(f"My first name is {first_name}")
print(f"You are {age} years old")

if is_student:
    print("You are a student!")
else:
    print("You are not a student!")
```

## Type casting

- The process of converting `a variable` from one data type to another.
- We have these functions: str(), bool(), int(), float()  
- You can check the datatype of a variable with `type()`. However, you have to use it within print() to print it out.

Let's check these examples:

```python
first_name = "Hieu" 
age = 21
gpa = 3.0

# int to float
print(type(age)) # This gives you <class 'int'>
age = float(age)
print(age) # 21.0

# float to int
gpa = int(gpa)
print(gpa) # truncate the decimal portion
print(type(gpa)) # <class 'int'>

# int to string
age = str(age)
print(age) # 21.0 is now a string
print(type(age)) 

```

Extra: numberic datatype can do arithemic expression while literal datatypes don't

```python
string_var = "1" 
int_var = 1
string_var = string_var + 1
int_var += 1
print(string_var)
print(int_var)
```

Extra-extra content:

- when you type-cast a string variable  to boolean, the variable remains true as long as it is not an empty string
- This is useful when it comes to checking whether a user has entered their name or not, they will be prompted to enter their name if they have not.

```python
text = "Hello"
text = bool(text)
print(text) # True
```

## Get user's input

The `input()` function collects what you type into the terminal and return the entered data as a string for other functions which might use it.

```python
print(input("Your name, please?: "))
# You can even assign what you input directly into a variable and type-cast it if necessary
name = input("Your name, please?: ")
age = int(input("How old are you?: ")) # type cast the string value that you input into integer
print(f"Hi {name}, you are {age}, aren't you?")
```

## if ... else ... elif

A condition statement, come on, you've already learned this for thousand times. You just need to remember the structure of conditional statement in Python:

```txt
if <condition>: // Remmber it must be a colon 
    Do something... // Rembmer to tab in
elif <condition>: // Just like if but if the "if" block fails, elif's block will execute.
    Do something...
else: // Last resort, execute when every block above evaluates to false
    Do something...
```

For example.

```python
age = int(input("Enter your age: "))

if age >= 100:
    print("Hi grandpa!")
elif age >= 50:
    print("Oh, a gentleman")
elif age >= 18:
    print("You are liable for all your troubles")
else:
    print("Just live as exuberant as you can before it's all over.")
```

Another example for boolean datatype:

```python
answer = str(input("Are you dumb?: "))\
is_dumb = False

if answer == "Yes":
    is_dumb = True
else:
    is_dumb = False

if is_dumb:
    print("Yes, I am")
else:
    print("No, I am not")
```

You can use `pass` keyword as a placeholder for if, elif, and else code blocks so that you can fill it in later.

### Conditional expression

- A short-hand for if else expression, it is also called a ternary operator you might as well heard in other programming languages.
- Here is the syntax `X if <condition> else Y`
  - It functions as how we read it: return X if condition is true, otherwise, return Y

```python
age = int(input("Please enter your age: "))
print("You are old" if age >= 18 else "You are young")
```

## Exercises and examples

### Regular exercises

1. [Madlibs](Madlibs.py)
2. [Rectangle_area](Rectangle_Area.py)
3. [ShoppingCart](ShoppingCart.py)
4. [Calculator](Exercises/Calculator.py)\
5. [Temperature_converter](Exercises/Temperature_converter.py)

### Arithemic and Math exercises

1. [Circumference](Circumference.py)
2. [Circle_area](Circle_Area.py)
3. [Hypotenuse](Hypotenuse.py)
