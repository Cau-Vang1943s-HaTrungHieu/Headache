# Common python statements

## print()

### f-string

A formatted string literal or f-string is a string literal that is prefixed with ‘f’ or ‘F’. Unlike other string literals, f-strings do not have a constant value. They may contain replacement fields delimited by curly braces {}. Replacement fields contain expressions which are evaluated at run time [^1]. For example:

```python
first_name = "Hieu"
age = 21
print(f"My first name is {first_name}")
print(f"You are {age} years old")
```

[^1]: [Python_lexical_analysis](https://docs.python.org/3/reference/lexical_analysis.html#f-strings)