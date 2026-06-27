## What Is Recursion?

**Recursion** happens when a function calls itself. There must be some **base condition** that terminates the recursion.

**Recursion has 2 phases:**
1. Ascending phase (calling)
2. Descending phase (returning)

## Types of Recursion

1. [Tail Recursion](tail-recursion.md)
2. [Head Recursion](head-recursion.md)
3. [Tree Recursion](tree-recursion.md)
4. [Indirect Recursion](indirect-recursion.md)
5. [Nested Recursion](nested-recursion)

## The Stack

Every single time a function calls itself, a new **activation record** (also known as a **stack frame**) is pushed onto the call [Stack](stack-memory.md).

 For each call, the stack frame keeps track:
- **Local variables** (like `int x`)
- **Parameters** passed into the function (like your `int n`)
- **The Return Address** (so the program knows _exactly_ which line of code to jump back to once that specific function call finishes)

```txt
|===================================|
|  fun(Base Case) Frame             | <- CURRENT TOP OF STACK
|  • Condition met (e.g., n == 0)   |    Triggers the halt! Returns a value,
|  • Status: ACTIVE 🟢              |    collapsing this frame immediately.
|-----------------------------------|
|  fun(Last Step) Frame             | <- SUSPENDED FRAME
|  • Status: PAUSED 🟡              |    Waiting for the Base Case above
|  • Holds: Local data / Arguments  |    to return its value so it can finish.
|-----------------------------------|
|  ... More Paused Frames ...       | <- SUSPENDED FRAMES
|  • Status: PAUSED 🟡              |    Each call stacks neatly on top of the
|  • Holds: Local data / Arguments  |    previous one, allocating new memory.
|-----------------------------------|
|  fun(Initial Call) Frame          | <- THE ENTRY POINT
|  • Status: PAUSED 🟡              |    The very first recursive call sparked
|  • Holds: Original input data     |    by your driver code.
|-----------------------------------|
|  main() / Global Execution Frame  | <- THE BASE LAYER
|  • Status: PAUSED 🟡              |    Pushed first. Handed control over to 
|  • Holds: Program entry variables |    the recursive function; waiting to resume.
|===================================|
           STACK (RAM)
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

