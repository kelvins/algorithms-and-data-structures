# 1 - open your terminal and type: pip install pythonds

# 2 - of this package below, download the 'Deque' module 
from pythonds.basic.deque import Deque

# to better understand what a 'deck' is about, check out:
# https://runestone.academy/runestone/books/published/pythonds/BasicDS/WhatIsaDeque.html

# 3 - the function will tell you if that word is palindrome
def checking(reading2ring):
    character_deque = Deque()
    for word in reading2ring:
        character_deque.addRear(word)
    equity = 'right'

# 4 - the 'while' loop will read the information placed
    while (character_deque.size() > 1 and equity):
        reading1 = character_deque.removeFront() # add the element at the rear
        reading2 = character_deque.removeRear() # removes the element at the rear

# 5 - the 'if' loop will give the 'wrong' answer
        if (reading1 != reading2):
            equity = 'wrong'
    return equity

# 6 - check the result - always invoking the function 'checking ()'
print(checking("hannah")) # example1 : correto
print(checking("abcabc")) # example2 : errado