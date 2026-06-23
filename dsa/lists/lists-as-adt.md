## Lists as Abstract Data Types

A **list** is an ordered collection of elements.
#### Static Lists

**With "static" lists we can:**
- Store a given number of elements of a given data type
- Write/modify an element at a specific position
- Read an element at a specific position

```cpp
int myArray[10];          // store
myArray[0] = 5;           // modify
cout << myArray[0];       // read
```
#### Dynamic Lists

**With "dynamic" lists we can:**
- Insert elements
- Remove elements
- Count the number of elements
- Read/modify elements at a specific position
- Specify the data type stored

But, how can this "dynamic" list be implemented? Using **==arrays==**!


