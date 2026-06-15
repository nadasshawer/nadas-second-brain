## Arrays

- In standard C/C++, an `int` occupies 4 bytes of memory
- If an array of a specific size is initialized but not all the elements are filled with actual values, the remaining elements will default to **0**
- **Variable-sized** arrays can **not** be initialized
### Declaration vs Initialization
#### Declaration

- Telling the compiler that a variable exists
- Does **not** assign the variable a value yet
- Just reserving a space for it in memory

```cpp
int A[5];
cout << sizeof(A);      // 20
```
#### Initialization

- Assigning the variable an actual value
- Putting data in the space for the first time

```cpp
int A[] = {1, 2, 3, 4, 5};
cout << sizeof(A);      // 28
```

## Structure

A **structure** is a collection of **related** data members of a **similar type** under one name.

- When declaring a structure inside a function, that structure belongs to the [[stack-memory|Stack]] of that function in memory
- Inside structures, [[padding]] of memory is done
#### Definition vs. Initialization vs. Declaration

```cpp
// Defination
struct Rectangle                      // not yet created in memory and does NOT occupy space
{
	int len;
	int width;
};

int main()
{
	struct Rectangle r;               // declaration (created in memory and occupies space)
	r.len = 10;
	r.width = 5;
	
	struct Rectangle r = {10, 5}      // initialization
}
```

## Pointers

A **pointer** is an **address variable** that is meant for storing the address of data, not the data itself. It's used for **indirectly** accessing the data.

- No matter what the data type of the pointer is, each pointer takes the **same amount of memory** → 8 bytes (on latest compilers)
#### Why Access Indirectly?

- [[heap|Heap]] memory is external to the program, outside of it
- Thus, the program can't access it directly
- To access it, a pointer is used
#### Usages

- Accessing the resources that are **outside** the program
	- [[heap|Heap]] memory
	- Hard disk files
	- Keyboards, monitors, internet, etc.
- Parameter passing
#### Declaration vs. Initialization vs. Dereferencing

- `*` → dereference operator
- `&` → address-of operator (when used in front of an already existing variable)

```cpp
int *p;         // declaration
p = &a;         // assignment or initialization (address)
cout << *p;     // dereferencing (actual value)
```
### Dynamic Memory Allocation
#### `malloc` Function

`malloc` stands for **M**emory **Alloc**ation.

Normally, when a variable like `int x;` is created, the computer automatically allocates memory for it on the [[stack-memory|Stack]]. This memory is managed for us and disappears when our function ends.

However, sometimes we don't know how much memory we will need until the program is actually running. `malloc` bypasses the [[stack-memory|Stack]] and goes straight to the [[heap|Heap]] to grab a custom-sized chunk of data that we control completely.
#### Allocation

```cpp
int main()
{
	int *p;
	p = int(*)malloc(5 * sizeof(int));    // C code
	p = new int[5];                       // C++ code
}
```
#### Deallocation

Deleting of variables in memory after they're finished working with.

```cpp
int main()
{
	int *p;
	delete [ ] p;           // C code
	free(p);                // C++ code
}
```
#### Arrays & Pointers

- The name of an array (`A`) is a **constant pointer** to its very **first element**

**Create an Array in Stack:**

```cpp
int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    int *p;
    p = A;
    
    cout << A;          // 0x2421bff980 → (address of first element of the array)
    cout << *p;         // 1 → (value of first element of the array)
    cout << p;          // 0x2421bff980 → (address of first element of the array)
    cout << &p;         // 0x2421bff978 → (address of the pointer itself in the stack) 
}
```

**Invalid Assignments:**

```cpp
p = &A;             // error: mismatching types
P = A[1];           // error: mismatching types
```

## References

1:15