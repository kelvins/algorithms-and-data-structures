## Java Language Basic Syntax Review
Java is a very popular general-purpose programming language, it is class-based and object-oriented. Java was developed by James Gosling at Sun Microsystems ( later acquired by Oracle) the initial release of Java was in 1995. Java 17 is the latest long-term supported version (LTS). As of today, Java is the world's number one server programming language with a 12 million developer community, 5 million students studying worldwide and it's #1 choice for the cloud development.

Key features:

- Well maintained
- Object-oriented
- Robust and Secure
- Multithreading
- Distributed Computing
- Dynamic and Extensible 
- Owned by oracle. Positive or negative you decide.

#### 1. Read Inputs

````java 
import java.util.Scanner;
class Input {
    public static void main(String[] args) {
    	Scanner input = new Scanner(System.in);
    	System.out.println("Enter your name: ");
    	String inp = input.next();
    	System.out.println("Hello, " + inp);
    }
}
````

#### 2. Variables

````java 
short x = 999; 			// -32768 to 32767
int   x = 99999; 		// -2147483648 to 2147483647
long  x = 99999999999L; // -9223372036854775808 to 9223372036854775807

float x = 1.2;
double x = 99.99d;

byte x = 99; // -128 to 127
char x = 'A';
boolean x = true;
````


#### 3. Loops and Conditionals

##### If-Else and If-Else:

When ever you want to perform a set of operations based on a condition If-Else is used.

```java
if(conditional-expression) {
  // code
} else {
  // code
}
```

##### Switch:
Switch is an alternative to If-Else-If ladder and to select one among many blocks of code.

```java
switch(<conditional-expression>) {    
case value1:    
 // code    
 break;  // optional  
case value2:    
 // code    
 break;  // optional  
...    
    
default:     
 //code to be executed when all the above cases are not matched;    
} 
```

##### For:

For loop is used to iterate a set of statements based on a condition. Usually for loop is preferred when number of iterations is known in advance.

````java
for(Initialization; Condition; Increment/decrement){  
    //code  
} 
````
##### While:

While is also used to iterate a set of statements based on a condition. Usually while is preferred when number of iterations are not known in advance.

````java
while(<condition>){  
 // code 
}  
````

##### Do-while:

Do-while is also used to iterate a set of statements based on a condition. It is mostly used when you need to execute the statements atleast once.

````java
do {
  // code 
} while (<condition>); 
````

##### 4. Classes and Objects:

Class is the blueprint of an object, which is also referred as user-defined data type with variables and functions. Object is a basic unit in OOP, and is an instance of the class.

**How to create a Class:**
`class` keyword is required to create a class.

````java
class Mobile {
    public:    // access specifier which specifies that accessibility of class members 
    string name; // string variable (attribute)
    int price; // int variable (attribute)
};
````
**How to create a Object:**
````java
Mobile m1 = new Mobile();
````
**How to define methods (functions) in a class:**

````java
public class Greeting {
    static void hello() {
        System.out.println("Hello.. Happy learning!");
    }

    public static void main(String[] args) {
        hello();
    }
}
````
