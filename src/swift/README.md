## Swift Language Basic Syntax Review
Swift 4 is a new programming language developed by Apple Inc for iOS and OS X development. Swift 4 adopts the best of C and Objective-C, without the constraints of C compatibility. Swift 4 uses the same runtime as the existing Obj-C system on Mac OS and iOS, which enables Swift 4 programs to run on many existing iOS 6 and OS X 10.8 platforms.


Key features:
- Makes use of safe programming patterns.
- Provides modern programming features.
- Provides Objective-C like syntax.
- A fantastic way to write iOS and OS X apps.
- Provides seamless access to existing Cocoa frameworks.
- Unifies the procedural and object-oriented portions of the language.
- Does not need a separate library import to support functionalities like input/output or string handling.


##### 1. Variabels
Variable is a name given to the storage area in order to identify them in our programs.

```swift
var variableName = <initial value>
```

##### 2. Loops and Conditionals

We have covered conditional ** operator ? :** in the previous chapter which can be used to replace if...else statements. It has the following general form −

````swift
Exp1 ? Exp2 : Exp3;
````

The syntax of an** if...else if...else** statement in Swift 4 is as follows −


````swift
if boolean_expression_1 {
   /* Executes when the boolean expression 1 is true */

} else if boolean_expression_2 {
   /* Executes when the boolean expression 2 is true */

} else if boolean_expression_3 {
   /* Executes when the boolean expression 3 is true */

} else {
   /* Executes when the none of the above condition is true */
}
````

**Nested IF-Else**: 
The syntax for a nested if statement is as follows −

````scala

if boolean_expression_1 {
   /* Executes when the boolean expression 1 is true */
   
   if boolean_expression_2 {
      /* Executes when the boolean expression 2 is true */
   }
}
````

##### For:

For loop performs a set of statements for each item in a range, sequence, collection, or progression.

`````swift
for index in var {
   statement(s)
}
`````

##### While:

A while loop statement  repeatedly executes a target statement as long as a given condition is true.

`````swift
while condition {
   statement(s)
}
````
##### repeat-while:
A repeat...while loop is similar to a while loop, except that a repeat...while loop is guaranteed to execute at least once.


`````swift
repeat {
   statement(s);
} 
while( condition );
`````

#### 3. Function
Function is a sub-routine which contains set of statements. Usually functions are written when multiple calls are required to same set of statements which increases re-usuability and modularity.

````swift
func funcname(Parameters) -> returntype {
   Statement1
   Statement2
   ---
   Statement N
   return parameters
}
````
##### Invoking a Function

````swift
funcname(val1,val2,valN)
````
