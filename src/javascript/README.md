## JavaScript Language Basic Syntax Review
Javascript(JS) is a object-oriented programming language which adhere to ECMA Script Standards. Javascript is required to design the behaviour of the web pages.

Key features:

- Open-source
- Just-in-time compiled language
- Embedded along with HTML and makes web pages alive
- Originally named as LiveScript.
- Executable in both browser and server which has Javascript engines like V8(chrome), SpiderMonkey(Firefox) etc.

#### 1. Read Inputs

````js
var readline = require('readline');
var rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false
});

rl.on('line', function(line){
    console.log("Hello, " + line);
});
````

#### 2. Variables

| Keyword  |  Description |Scope  |
| ------------ | ------------ | ------------ |
| var  |Var is used to declare variables(old way of declaring variables)| Function or global scope  |
| let  |let is also used to declare variables(new way)  | Global or block Scope  |
| const  | const is used to declare const values. Once the value is assigned, it can not be modified  | Global or block Scope  |

##### Backtick Strings
Interpolation: 
```js
let greetings = `Hello ${name}`
```
Multi line Strings:
```js
const msg = `
hello
world!
`
```
##### Arrays
An array is a collection of items or values.

```js
let arrayName = [value1, value2,..etc];
// or
let arrayName = new Array("value1","value2",..etc);
```

##### Arrow functions
Arrow Functions helps developers to write code in concise way, it’s introduced in ES6. Arrow functions can be written in multiple ways. Below are couple of ways to use arrow function but it can be written in many other ways as well.

````js
() => expression

//const numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
//const squaresOfEvenNumbers = numbers.filter(ele => ele % 2 == 0)
//                                  .map(ele => ele ** 2);
//console.log(squaresOfEvenNumbers);
````

##### De-structuring Arrays
````js
let [firstName, lastName] = ['Foo', 'Bar']
````

##### De-structuring Objects
````js
let {firstName, lastName} = {
  firstName: 'Foo',
  lastName: 'Bar'
}
````
##### De-structuring rest(...) operator
````js
 const {
    title,
    firstName,
    lastName,
    ...rest
  } = record;
````
##### De-structuring Spread(...) operator
````js
//Object spread
const post = {
  ...options,
  type: "new"
}
//array spread
const users = [
  ...adminUsers,
  ...normalUsers
]
````

#### 3. Functions

````js
function greetings({ name = 'Foo' } = {}) { //Defaulting name to Foo
  console.log(`Hello ${name}!`);
}
 
greet() // Hello Foo
greet({ name: 'Bar' }) // Hi Bar
````

##### 4. Loops and Conditionals

IF is used to execute a block of code based on a condition.

```js
if(condition){
    // code
}
```

Else part is used to execute the block of code when the condition fails.

````js
if(condition){
    // code
} else {
    // code
}
````

##### Switch:
Switch is used to replace nested If-Else statements.
```js
switch(condition){
    case 'value1' :
        //code
        [break;]
    case 'value2' :
        //code
        [break;]
    .......
    default :
        //code
        [break;]
}
```

##### For:

For loop is used to iterate a set of statements based on a condition.

````js
for(Initialization; Condition; Increment/decrement){  
//code  
} 
````
##### While:

While is also used to iterate a set of statements based on a condition. Usually while is preferred when number of iterations are not known in advance.

````js
while (condition) {  
  // code 
}  
````

##### Do-while:

Do-while is also used to iterate a set of statements based on a condition. It is mostly used when you need to execute the statements atleast once.

````js
do {
  // code 
} while (<condition>); 
````

##### 5. Classes

ES6 introduced classes along with OOPS concepts in JS. Class is similar to a function which you can think like kind of template which will get called when ever you initialize class.

**How to create a Class:**
`class` keyword is required to create a class.

````js
class className {
  constructor() { ... } //Mandatory Class method
  method1() { ... }
  method2() { ... }
  ...
}
````
