## What Is Recursion?

**Recursion** happens when a function calls itself. There must be some **base condition** that terminates the recursion.

**Recursion has 2 phases:**
1. Ascending phase (calling)
2. Descending phase (returning)
### Tail Recursion (Calling) Example

In `fun1`, the recursive call is the **very last operation** executed in the function.
#### Code

```cpp
void fun1(int n) 
{
    if (n > 0) 
    {
        printf("%d ", n);
        fun1(n - 1);
    }
}

// For fun1(3) -> Output: 3 2 1
// Time: O(n)
```
#### Recursive Tree

```txt
       fun1(3)
       /     \
      3      fun1(2)
             /     \
            2      fun1(1)
                   /     \
                  1      fun1(0)
                            |
                            X (Base case: 0 > 0 is false)
```
### Head Recursion (Returning) Example

In `fun2`, the recursive call is the **first operation** executed inside the conditional block.
#### Code

```cpp
void fun2(int n) 
{
    if (n > 0) 
    {
        fun2(n - 1);
        printf("%d ", n);
    }
}

// For fun2(3) -> Output: 1 2 3
// Time: O(n)
```

#### Recursive Tree

```txt
        fun2(3)
         /     \
     fun2(2)    3  (Prints last)
     /     \
 fun2(1)    2     (Prints second)
 /     \
fun2(0)    1      (Prints first)
   |
   X (Base case: 0 > 0 is false, returns)
```

## The Stack

Every single time a function calls itself, a new **activation record** (also known as a **stack frame**) is pushed onto the call [[stack-memory|Stack]].

 For each call, the stack frame keeps track:
- **Local variables** (like `int x`)
- **Parameters** passed into the function (like your `int n`)
- **The Return Address** (so the program knows _exactly_ which line of code to jump back to once that specific function call finishes)

```txt
|===================================|
|  fun2(0) Activation Record        | <- Current Top of Stack (Base case met! Returns)
|-----------------------------------|
|  fun2(1) Activation Record (n=1)  | <- Paused at line: printf("%d", n);
|-----------------------------------|
|  fun2(2) Activation Record (n=2)  | <- Paused at line: printf("%d", n);
|-----------------------------------|
|  fun2(3) Activation Record (n=3)  | <- Paused at line: printf("%d", n);
|-----------------------------------|
|  main() Activation Record         | <- Waiting for fun2(3) to finish
|===================================|
         STACK MEMORY CHUNK
```

## Time Complexity

- We assume that every code statement takes **one** unit of time
- If that statement is repeated `n` times,  the time taken is `n`
#### Recurrence Relation

A **recurrence relation** is a mathematical equation or inequality that defines a sequence or the running time of an algorithm **in terms of itself on smaller inputs**.

- $T(n)$ → total running time of a function (sum of all the times taken by the statements inside the function)

In the `fun1` example:

```cpp
void fun1(int n) {
    if (n > 0) {           // Takes constant time: O(1)
        printf("%d ", n);  // Takes constant time: O(1)
        fun1(n - 1);       // Calls itself with n-1: T(n-1)
    }
}
```

So, the **Recurrence Relation** for the code is:

$$T(n) = T(n-1) + 2 \quad \text{for } n > 0$$

$$T(0) = 1 \quad \text{for } n = 0$$
## Static Variables in Recursion

- Static variables are created inside the code section in memory
- They don't get created every time the function is called
- They have a **single** copy in memory
- All the calls for that function will use the same copy of the static variable
#### Code

```cpp
int fun3(int n) 
{
    static int x = 0;       // Allocated ONCE in global memory, NOT on the stack!
    if (n > 0) 
    {
        x++;                // Increments the SINGLE shared copy of x
        return fun(n - 1) + x; 
    }
    return 0;
}

// For fun3(5) -> Output: 1 2 3
```
#### Winding the Stack

```txt
        STACK MEMORY                           GLOBAL / STATIC MEMORY
|===========================|               |===========================|
| fun(5) Frame: [n = 5]     | ------------> | x changes: 0 -> 1         |
|---------------------------|               |---------------------------|
| fun(4) Frame: [n = 4]     | ------------> | x changes: 1 -> 2         |
|---------------------------|               |---------------------------|
| fun(3) Frame: [n = 3]     | ------------> | x changes: 2 -> 3         |
|---------------------------|               |---------------------------|
| fun(2) Frame: [n = 2]     | ------------> | x changes: 3 -> 4         |
|---------------------------|               |---------------------------|
| fun(1) Frame: [n = 1]     | ------------> | x changes: 4 -> 5 🛑      |
|---------------------------|               |===========================|
| fun(0) Frame: [n = 0]     | Base Case! Does not increment x. Returns 0.
|===========================|
```
#### Unwinding the Stack

```txt
        STACK MEMORY                           GLOBAL / STATIC MEMORY
|===========================|               |===========================|
| fun(1) Frame returns:     |               |                           |
|   fun(0) + x  =>  0 + 5   | ------------> | Read current value: [5]   |
|---------------------------|               |---------------------------|
| fun(2) Frame returns:     |               |                           |
|   fun(1) + x  =>  5 + 5   | ------------> | Read current value: [5]   |
|---------------------------|               |---------------------------|
| fun(3) Frame returns:     |               |                           |
|   fun(2) + x  => 10 + 5   | ------------> | Read current value: [5]   |
|---------------------------|               |---------------------------|
| fun(4) Frame returns:     |               |                           |
|   fun(3) + x  => 15 + 5   | ------------> | Read current value: [5]   |
|---------------------------|               |---------------------------|
| fun(5) Frame returns:     |               |                           |
|   fun(4) + x  => 20 + 5   | ------------> | Read current value: [5]   |
|===========================|               |===========================|
 FINAL RETURN VALUE: 25
```
