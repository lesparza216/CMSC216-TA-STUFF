# C Programming


## Table of Contents
- [Basics](#basics)
- [Memory Alignment](#memory-alignment)
- [Pointers](#pointers)
- [Dynamic memory allocation](#dynamic-memory-allocation)
- [Stack Management](#stack-management)



# Basics

## What is programming like in C?
- Programming in C is unlike Java in the sense that you have more control and there is less hand holding. In C you can directory keep track and modify memory addresses which can often be dangerous and lead to programs with security vulnerabilities. 

- The trade off is that you lose all the baggage with object oriented programming there is no concept of inheritance, Abstraction, and Encapsulation just to name a few.

- In C the only thing you will need to worry about is how things work in the low level
## Variables
- Just like java the main primitive types are here with a new familiar face and an old one missing
  - char (1 bytes)
  - short (2 bytes)
  - int (4 bytes)
  - long (8 bytes)
  - float (4 bytes) 
  - double (8 bytes)
  - pointer variables (8 bytes)
- As you probably notice there is no boolean type in C truth values are determine by integers where 0 denotes false and anything that is not 0 is true even -9999999
- Pointers are a special type of variable that hold an address of another variable this will be covered later
So what does a program in C look like?
```C
int main(int argc, char *argv){
    int x = 10;
    printf("Hello World!");
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
As mentioned before C is not an object oriented programming language concepts like public, private, protected etc are only exclusive to the object oriented paradigm. Although static is a key word in C and works almost the same as it's java counter part.




## Structures


# Memory Alignment


# Pointers


# Dynamic memory allocation




 


