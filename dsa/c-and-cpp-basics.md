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

