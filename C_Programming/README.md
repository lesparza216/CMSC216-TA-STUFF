# C Programming


## Table of Contents
- [Basics](#basics)
- [Memory Alignment](#memory-alignment)
- [Pointers](#pointers)
- [Dynamic memory allocation](#dynamic-memory-allocation)
- [Stack Management](#stack-management)



# Basics

### What is programming like in C?
- C falls under the **Procedural programming paradigm** meaning C is built around the idea that programs are sequences of instructions to be executed. For reference Java fell under the **Object-oriented programming** which is built around the idea of creating and interacting with objects that maintain state and encapsulate variables and methods. OOP focuses on concepts like classes, inheritance, polymorphism, encapsulation, and abstraction.

- Programming in C gives you more control over memory and hardware compared to Java, with less abstraction and more direct memory manipulation. This can lead to powerful and efficient programs but also introduces risks like security vulnerabilities.

- The trade off is that you lose all that comes with object oriented programming there is no concept of Abstraction, encapsulation, polymorphism, and inheritance in C.

- In C the only thing you will need to worry about is how things work in the low level
### Variables
Just like java the main primitive types are here with a new familiar face and an old one missing
| Variable           |Size                                  |
| -------------      | -------------                        |
| char               | 1 bytes                              |
| short              | 2 bytes                              |
| int                | 4 bytes                              |
| long               | 8 bytes                              |
| float              | 4 bytes                              |
| double             | 8 bytes                              |
| pointer variable   | 8 bytes                              |


As you probably notice there is no boolean type in C truth values are determine by integers where 0 denotes false and anything that is not 0 is true even (-9999999). 
  Pointers are a special type of variable that hold an address of another variable this will be covered later
***
### So what does a program in C look like?
```C
#include <stdio.h>
int main(int argc, char *argv){
    int x = 10;
    printf("Hello World!\n");
    return 0;
}
```
The java version would look something like this
```Java
public class PlayGround {
	public static void main(String[] argv) {
		int x = 10;
		System.out.println("Hello World!");
	}
}
```
As mentioned before C is not an object oriented programming language concepts like public, private, protected etc are only exclusive to the object oriented paradigm. However, the static keyword in C serves a similar purpose to Java. In addition there is no concepts of string in C we use an array of characters to represent strings.
  
  However, notice the following
  ```C
  #include <stdio.h>
  ```
  Just like in Java if you wanted to include functions you will need later down the line you will need to include them just like in Java you would do the following
  ```Java
  import java.util.Scanner;
  ```
  Despite the major differences due to having completely different paradigms, some things work almost the same. For example, to print "Hello, World!" ten times in C:
  ```C
  #include <stdio.h>
  int x; // Global variables exist too and unlike variables declared inside functions they are initialize to 0
  int main(void){
    int i = 0;

    for(i = 0; i < 10;i++){
        printf("Hello World!\n");
    }
    
    return 0; // Always return 0 to tell linux our program was successful and reached the end
  }

  ```
***
### Printf function and format specifiers
C uses printf to print strings and variables to standard out (aka your screen) which is brought to you by <stdio.h> 
```C
int x = 10;
printf("The value of x is %d",x);
```
In the example above you notice in order to print variables we must have a format specifier in this case %d to print out variables below are a table of all them.
| SPECIFIER     | USED FOR                                      |
| ------------- | ----------------------------------------------|
| %c            | char                                          |
| %hi           | short (signed)                                |
| %hu           | short (unsigned)                              |
| %d            | integer in decimal                            |
| %o            | integer in octal                              |
| %x            | integer in hexadecimal                        |
| %u            | unsigned integer in decimal                   |
| %f            | float                                         |
| %e            | floating point number in scientific notation  |
| %Lf           | long double                                   |
| %p            | an address or pointer                         |
| %zu           | printing size_t variables (just nice to know) |

***
### Basic rules
  Since follows a different paradigm there are some rules you must follow that was not present in Java.

- Function prototypes must always be declared meaning suppose we had the following C program
```C
#include <stdio.h>
int main(int argc, char *argv){
    int x = 10;
    char c = func(x);
    printf("%c Was the character\n",c);
    return 0;
}
char func(int x){
    if(x == 10){
        return 'A';
    }else{
        return 'B';
    }
}
```
This will not compile because at compile time the program has no idea what func is since there was never a reference to it before. Imagine out of no where you saw the following
```C
var = 2;
```
Is var a short or an int or a float or what we have no idea because we never saw what type var was before.

  Likewise the compiler sees the function being called and does not understand what type it is so a simple fix would be the following
```C
#include <stdio.h>

//Declare the prototype so C knows what it is dealing with

char func(int); // The prototype is just the return type, name, and parameter types

int main(int argc, char *argv){
    int x = 10;
    char c = func(x); // Now our program knows exactly what this is
    printf("%c Was the character\n",c);
    return 0;
}
char func(int x){
    if(x == 10){
        return 'A';
    }else{
        return 'B';
    }
}
```
- No function overloading two functions can not share the same name even if they have different parameters and argument types

- **NOTHING IN C IS EVER INITIALIZE EXCEPT GLOBAL VARIABLES** this is an important thing to know because unlike java declaring variables like
```C
int x; // The value is not zero it's garbage could be anything
```
Does not automatically set the value to 0 it will be given a random value during each compile this is not true for **global variables**



# Structures

- You can think of structures as like Classes in Java meaning if you break it down at it's fundamentally core what was a class in Java?
Just a bunch of methods and variables put together in a nice package unlike structures are exactly that minus the method part.

  We typically declare structures in C via the following syntax 
``` C
struct NAME{
    // Variable 1
    // Variable 2
    // Variable 3
};
``` 
We can then access each field of a struct via the following syntax
```C
struct NAME EXAMPLE; 
EXAMPLE.Variable_1;
EXAMPLE.Variable_2;
EXAMPLE.Variable_3; 
//And so on observe the following example
```
  ## Example 1
```C
#include <stdio.h>
#include <string.h>
struct student {
   int ID;
   int age;
      };

int main(void){
  struct student UMD_Student;
  UMD_Student.ID = 118247842;
  UMD_Student.age = 19;
  printf("Student name and email (soon), age %d and ID %d\n",UMD_Student.age,UMD_Student.ID);
  return 0;
}
```
In this basic Example we declare a student structure and initialize it's fields using the same dot notation we know in Java.

## Example 2 
``` C
#include <stdio.h>
#include <string.h>
typedef struct student {
    int ID;
    int age;
    char name[128]; // There are no strings in C only arrays of characters
    char email[128];
} Student;

int main(void) {
    Student UMD_Student;
    UMD_Student.ID = 118247842;
    UMD_Student.age = 19;
    strcpy(UMD_Student.name, "John Doe");
    strcpy(UMD_Student.email, "Jdoe@email.com");

    printf("Student name's: %s, email: %s, age: %d and ID: %d\n",
           UMD_Student.name, UMD_Student.email, UMD_Student.age,
           UMD_Student.ID);
    return 0;
}
```
Using the same example as before as you can see we modified the fields a little bit by adding an email and name field.
By making use of the string library strcpy() function we are able to initialize the fields of the name and email array field.

  In addition notice use of the typedef keyword what this does is assign types an alias so unlike in the previous example instead of declaring my structure by struct student I used typedef to give the entire thing an Alias that of Student which I can use instead of the struct student tag






# Memory Alignment

```C
#include <stdalign.h>
#include <stddef.h>
#include <stdio.h>

int main(void) {
    printf("Alignment of char = %zu\n", alignof(char));
    printf("Alignment of short = %zu\n", alignof(short));
    printf("Alignment of int = %zu\n", alignof(int));
    printf("Alignment of float = %zu\n", alignof(float));
    printf("Alignment of double = %zu\n", alignof(double));
    printf("Alignment of Pointer = %zu\n", alignof(void *));

}
```


# Pointers


# Dynamic memory allocation




 


