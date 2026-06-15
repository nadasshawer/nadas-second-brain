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

- When declaring a structure inside a function, that structure belongs to the **stack** of that function in memory
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

49:19