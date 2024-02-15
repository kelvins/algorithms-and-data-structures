## Python Language Basic Syntax Review
Python is a very popular general-purpose programming language which was created by Guido van Rossum, and released in 1991. It is very popular for web development and you can build almost anything like mobile apps, web apps, tools, data analytics, machine learning etc. It is designed to be simple and easy like english language. It's is highly productive and efficient making it a very popular language.

***NOTE Indentation is very important in Python, make sure the indentation is followed correctly***


Key features:

- Most popular and beginner friendly.
- Learn it now.

#### 1. Taking inputs

````python
import sys
name = sys.stdin.readline()
print("Hello "+ name)
````

##### 2. Loops and Conditionals




**IF-Else**: 
Used to execute a block of code based on a condition. Else part is used to execute the block of code when the condition fails.

````python
if conditional-expression
    #code
elif conditional-expression
    #code
else:
    #code
````
##### For:

For loop is used to iterate over arrays(list, tuple, set, dictionary) or strings.

`````python
mylist=("Iphone","Pixel","Samsung")
for i in mylist:
    print(i)
````
##### While:

While is also used to iterate a set of statements based on a condition. Usually while is preferred when number of iterations are not known in advance.

````python
while condition  
    #code 
````

#### 3. Collections
There are four types of collections in Python.

##### List:
List is a collection which is ordered and can be changed. Lists are specified in square brackets.

````python
mylist=["iPhone","Pixel","Samsung"]
print(mylist)
````
##### Tuple:
Tuple is a collection which is ordered and can not be changed. Tuples are specified in round brackets.

````python
myTuple=("iPhone","Pixel","Samsung")
print(myTuple)
````
##### Set:
Set is a collection which is unordered and unindexed. Sets are specified in curly brackets.

````python
myset{"iPhone","Pixel","Samsung"}
print{myset}
````

##### Dictionary:
Dictionary is a collection of key value pairs which is unordered, can be changed, and indexed. They are written in curly brackets with key - value pairs.

````python
mydict = {
    "brand" :"iPhone",
    "model": "iPhone 11"
}
print(mydict)
````