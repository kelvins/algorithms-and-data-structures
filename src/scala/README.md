## Scala Language Basic Syntax Review
Scala is both object-oriented and functional programming language by Martin Odersky in the year 2003.


Key features:
- Concise syntax
- Expressive type system
- Support for both functional and object-oriented programming
- Seamless interaction with Java

#### 1. Taking inputs

````scala
object Hello {
	def main(args: Array[String]): Unit = {
	  val name = scala.io.StdIn.readLine()    
    println("Hello " + name ) 
	}
}
````

##### 2. Variabels
Variable is a name given to the storage area in order to identify them in our programs.

```scala
var or val Variable-name [: Data-Type] = [Initial Value];
```

##### 3. Loops and Conditionals

**IF-Else**: 
If, If-else, Nested-Ifs are used when you want to perform a certain set of operations based on conditional expressions.

````scala
if(conditional-expression) {  
//code if condition is true  
} else {  
//code if condition is false  
} 
````

**Nested IF-Else**: 

````scala
if(condition-expression1) {  
//code if above condition is true  
} else if (condition-expression2) {  
//code if above condition is true  
}  
else if(condition-expression3) {  
//code if above condition is true  
}  
...  
else {  
//code if all the above conditions are false  
}  
````

##### For:

For loop is used to iterate a set of statements based on a criteria.

`````scala
for(index <- range){  
  // code  
} 
`````
##### While:

While is also used to iterate a set of statements based on a condition. Usually while is preferred when number of iterations are not known in advance.

`````scala
while(condition) {  
 // code 
}  
`````
##### Do-while:
Do-while is also used to iterate a set of statements based on a condition. It is mostly used when you need to execute the statements atleast once.

`````scala
do {
  // code 
} while (condition) 
`````
#### 4. Function
Function is a sub-routine which contains set of statements. Usually functions are written when multiple calls are required to same set of statements which increases re-usuability and modularity.

````scala
def functionname(parameters : parameters-type) : returntype = {   //code
}
`````
You can either use `=` or not in the function definition. If `=` is not present, function will not return any value.


