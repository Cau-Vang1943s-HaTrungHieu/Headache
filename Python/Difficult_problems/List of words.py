def greaterThan3_word(lst_of_str):
    result = []
    for word in lst_of_str:
        if (len(word) > 3 and word not in result):
            result.append(word)
    return result

str = input()
lst_of_str = str.split()
print(greaterThan3_word(lst_of_str))

# More efficient and short one
'''
text = input()
lst_of_words = [word for word in text.split() if len(word) > 3]
print(lst_of_words)
'''