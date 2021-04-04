# a simplified way to resolve the issue of palindromes.

reading1 = input("insert the word: ")

# reading2 receives the variable (only the other way around)
reading2 = reading1[::-1] 

# return True or False (depending on the input value)
if (reading1 == reading2):
    print(True)
else:
    print(False)