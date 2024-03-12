## C++ Language Basic Syntax Review
C++ is one of the most popular programming languages. C++ can be found in todays operating systems, Graphical User Interfaces, and embedded systems. C++ is an object-oriented programming language which gives a clear structure to programs and allows code to be reused, lowering development costs. Note, C++ is an extension of C.

Key features:

- Supports different platforms like Windows, various Linux flavours, MacOS etc
- C++ supports OOPS concepts like Inheritance, Polymorphism, Encapsulation and Abstraction.
- Case-sensitive
- C++ is a compiler based language
- C++ supports structured programming language
- C++ provides alot of inbuilt functions and also supports dynamic memory allocation.
- Like C, C++ also allows you to play with memory using Pointers.


#### 1. Read inputs 
````cpp
#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string name;
    cout << "Enter name:";
    getline (cin, name);
    cout << "Hello " << name;
    return 0;
}
}
````
#### Loops and Conditionals

##### 2. If-Else:

When ever you want to perform a set of operations based on a condition if-else is used.
```cpp
if(conditional-expression) {
   // code
} else {
   // code
}
```
You can also use if-else for nested Ifs and if-else-if ladder when multiple conditions are to be performed on a single variable.

##### 3. Switch:

Switch is an alternative to if-else-if ladder.

````cpp
switch(conditional-expression) {    
case value1:    
 // code    
 break;  // optional  
case value2:    
 // code    
 break;  // optional  
...    
    
default:     
 // code to be executed when all the above cases are not matched;    
} 
````

##### 4. For:

For loop is used to iterate a set of statements based on a condition.

````cpp
for(Initialization; Condition; Increment/decrement){  
  // code  
} 
````

##### 5. While:

While is also used to iterate a set of statements based on a condition. Usually while is preferred when number of iterations are not known in advance.

````cpp
while(condition) {  
 // code 
}  
````

##### 6. Do-While:

Do-while is also used to iterate a set of statements based on a condition. It is mostly used when you need to execute the statements atleast once.

````cpp
do {
  // code 
} while (condition); 

````
#### 7. Arrays
Array is a collection of similar data which is stored in continuous memory addresses. Array values can be fetched using index. Index starts from 0 to size-1.

1. One dimentional Array: ` data-type array-name[size];`
2. Two dimensional array: `data-type array-name[size][size];`

#### 8. Functions
Function is a sub-routine which contains set of statements. Usually functions are written when multiple calls are required to same set of statements which increases re-usuability and modularity.

Two types of functions are present in C++

1. Library Functions: Library functions are the in-built functions which are declared in header files like `floor(x)`, `tolower(x)`, `toupper()` etc.,
2. User defined functions: User defined functions are the ones which are written by the programmer based on the requirement.


##### How to declare a Function
```cpp
return_type function_name(parameters);`
```
##### How to call a Function
```cpp
function_name (parameters)
```

##### How to define a FunctionHow to define a Function
```cpp
return_type function_name(parameters) {  
  //code
}
```