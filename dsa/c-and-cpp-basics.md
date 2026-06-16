## Arrays

- In standard C/C++, an `int` occupies 4 bytes of memory
- If an [array](arrays.md) of a specific size is initialized but not all the elements are filled with actual values, the remaining elements will default to **0**
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

A [structure](structures) is a collection of **related** data members of a **similar type** under one name.

- When declaring a structure inside a function, that structure belongs to the [Stack](stack-memory.md) of that function in memory
- Inside structures, [padding](padding.md) of memory is done
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

A [pointer](pointers) is an **address variable** that is meant for storing the address of data, not the data itself. It's used for **indirectly** accessing the data.

- No matter what the data type of the pointer is, each pointer takes the **same amount of memory** → 8 bytes (on latest compilers)
#### Why Access Indirectly?

- [heap](Heap.md) memory is external to the program, outside of it
- Thus, the program can't access it directly
- To access it, a pointer is used
#### Usages

- Accessing the resources that are **outside** the program
	- [heap](Heap.md) memory
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
#### Pointer To Structure



### Dynamic Memory Allocation
#### `malloc` Function

- `malloc` → **M**emory **Alloc**ation
- It's a C function used to allocate dynamic memory in the [Heap](heap.md)
- It returns a **void pointer**

Normally, when a variable like `int x;` is created, the computer automatically allocates memory for it on the [Stack](stack-memory.md). This memory is managed for us and disappears when our function ends.

However, sometimes we don't know how much memory we will need until the program is actually running. `malloc` bypasses the [Stack](stack-memory.md) and goes straight to the [heap](Heap.md) to grab a custom-sized chunk of data that we control completely.
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

A [reference](references) is a nickname given to a variable. When declaring, references they **must be initialized**.

**References:**
- don't consume memory
- use the same memory as the variable they're referencing
- are **not** pointers
- are only available in C++ , not C
#### Usage

- Parameter passing

```cpp
int a = 10;
int &r = a;          // reference to variable a
```

## Functions

A **function** is a piece of code that performs a specific task.
#### Benefits

- Each function will have its own activation record, which separates the set of variables inside the memory
- When the function is called, these records are created
- When the function terminates, these records are destroyed
- One function can't access the variables of another function

```cpp
void func(int x, int y) {      // formal parameters
    return a + y;
}

int main() {
    int a = 5;
    int b = 10;
    sum(a, b);                 // actual parameters
    return 0;
}
```
#### Parameter Passing

**Call by Value:**
- Any change done to formal parameters won't reflect in actual parameters
- Used when we **don't need to modify actual parameters**
- Or when a function only needs to process data and return a value

**Call by Address (`Type*`):**
- Uses *pointers* to modify actual parameters
- The pointer consumes space in memory
- Used to **modify actual parameters**
- Or when the argument can be null
- Or when the pointer can change to point to a different memory address

**Call by Reference (`Type&`):**
- Not allowed in C, only in C++
- The reference doesn't consume space in memory
- Should be used carefully, not always
- A reference **must** always refer to a real variable, it can never be null

## Arrays as Parameters

2:18:40