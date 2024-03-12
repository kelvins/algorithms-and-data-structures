## Go Language Basic Syntax Review
Go language is an open-source, statically typed programming language by Google. Go is highly recommended for creation of highly scalable and available web applications.
Some of the products developed using Go are Kubernetes, Docker, Dropbox, Infoblox etc.

Key features:

- Fast compilation
- Easy to write concurrent programs
- Simple and concise syntax
- Supports static linking
- Opensource and huge community support.

#### 1. Read Inputs

````go 
package main
import "fmt"

func main() {
  var name string 
  fmt.Scanf("%s", &name) 
	fmt.Printf("Hello %s", name)
}
````

#### 2. Variables

````elixir 
var varible-names datatype;
````


#### 3. Loops and Conditionals

##### If-Else and If-Else:

When ever you want to perform a set of operations based on a condition If is used.

```go
if(conditional-expression) {
   // code
} 
```

When there is requirement to add code for false condition to IF-ELSE block.

```go
if(conditional-expression) {
   // code
} else {
   // code
}
```
When there is requirement to have nested IF-ELSE block.

```go
if(conditional-expression) {
   // code
} else if(conditional-expression) {
   // code
} else {
   // code
}
```

##### Switch:
Switch is an alternative to If-Else-If ladder.

```go
switch conditional-expression {    
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
```
*Note: Go doesn't have while or do-while loops like in C.*

##### For:

For loop is used to iterate a set of statements based on a condition.

````go
for Initialization; Condition; Increment/decrement {  
  // code  
} 
````

#### 4. Functions
Function is a sub-routine which contains set of statements. Usually functions are written when multiple calls are required to same set of statements which increases re-usuability and modularity.

```go
func functionname(parameter-name type) returntype {  
 //code
}
```