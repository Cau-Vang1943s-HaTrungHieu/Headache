def is_palindrome(s):
    cleaned = ''.join(c.lower() for c in s if c.isalnum())
    stack = []
    for c in cleaned:
        stack.append(c)
    return cleaned == ''.join(reversed(stack))

s = input()
if is_palindrome(s):
    print("YES")
else:
    print("NO")