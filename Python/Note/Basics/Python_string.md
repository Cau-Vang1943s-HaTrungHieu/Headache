# Python string

There are many things to do with string beside declaring it like concatenation, string methods, etc.

## Methods

When you declare a string variable, the variable becomes a class itself, which means not only can you use Python built-in functions on it (like len(), etc.), but also operate its value with string methods as well.

There are various string methods to use in Python. However, this file only names a few common ones:

- `len()` : Python built-in function returns the length of a string
- `.find()` : find the first character in a string
- `.rfind()` : reversely find the frist character in a string (find the first character in a string from right to left)
- `.count()` : counts the number of **the specified character** in a string
- `.capitalize()`: Capitalizes the first character of a string
- `.upper()` : Capitalises the whole string
- `.lower()` : Put the whole string into lowercase
- `.isalpha()` : Returns True if a string is all alphabet characters.
- `.isdigit()` : Returns True if a string contains only digits
- `.replace()` : Replaces specified character(s) in a string with different character(s). This method will return a new string.

You can use `print(help(str))` to print a comprehensive list of string's methods or you can look it up in Python documentation.

