## Rust Language Basic Syntax Review
Rust is a modern systems programming language developed by the Mozilla Corporation. It is intended to be a language for highly concurrent and highly secure systems. It compiles to native code; hence, it is blazingly fast like C and C++. This tutorial adopts a simple and practical approach to describe the concepts of Rust programming.


Key features:
- Safety
- Speed
- Concurrency


##### 1. Variabels
The data type is optional while declaring a variable in Rust. The data type is inferred from the value assigned to the variable.

The syntax for declaring a variable is given below.
```rust
let variable_name = value;            // no type specified
let variable_name:dataType = value;   //type specified
```

##### 2. Loops and Conditionals

##### For:

The for loop executes the code block for a specified number of times. It can be used to iterate over a fixed set of values, such as an array. The syntax of the for loop is as given below


`````rust
for temp_variable in lower_bound..upper_bound {
   //statements
}
`````

#### 3. Function
A function definition specifies what and how a specific task would be done. Before using a function, it must be defined. The function body contains code that should be executed by the function. The rules for naming a function are similar to that of a variable. Functions are defined using the `fn` keyword. The syntax for defining a standard function is given below

````rust
fn function_name(param1,param2..paramN) {
   // function body
}
````
##### Invoking a Function

````rust
function_name(val1,val2,valN)

````

