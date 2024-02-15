## Kotline Language Basic Syntax Review
Kotlin is a new open source programming language like Java, JavaScript, Python etc. It is a high level strongly statically typed language that combines functional and technical part in a same place. Currently, Kotlin mainly targets the Java Virtual Machine (JVM), but also compiles to JavaScript.

Kotlin is influenced by other popular programming languages such as Java, C#, JavaScript, Scala and Groovy. The syntax of Kotlin may not be exactly similar to Java Programming Language, however, internally Kotlin is reliant on the existing Java Class library to produce wonderful results for the programmers. Kotlin provides interoperability, code safety, and clarity to the developers around the world.

Kotlin was developed and released by JetBrains in 2016. Kotlin is free, has been free and will remain free. It is developed under the Apache 2.0 license and the source code is available on GitHub.

Key features:

- Cross-platform Mobile applications.
- Android Application Development.
- Web Application Development
- Server Side Applications
- Desktop Application Development
- Data science based applications


#### 1. Variables

```kotlin
var name = "Zara Ali"
var age = 19
var height = 5.2
```


##### 2. Loops and Conditionals

**IF**: 
Used to execute a block of code based on a condition. Else part is used to execute the block of code when the condition fails.

````kotlin
if (condition) {
   // code block A to be executed if condition is true
} else {
  // code block B to be executed if condition is false
}
````

##### When:
Kotlin when expression is similar to the switch statement in C, C++ and Java.
```kotlin
fun main(args: Array<String>) {
   val day = 2

   val result = when (day) {
     1 -> "Monday"
     2 -> "Tuesday"
     3 -> "Wednesday"
     4 -> "Thursday"
     5 -> "Friday"
     6 -> "Saturday"
     7 -> "Sunday"
     else -> "Invalid day."
   }
   println(result)
}
```

##### For:

Kotlin does not provide a conventional for loop which is available in C, C++ and Java etc.

`````kotlin
for (item in collection) {
    // body of loop
}
````
##### While:

While is also used to iterate a set of statements based on a condition. Usually while is preferred when number of iterations are not known in advance.

````js
while (condition) {  
  // code 
}  
````