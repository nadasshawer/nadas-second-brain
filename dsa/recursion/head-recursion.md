## Head Recursion (Returning)

**Head recursion** happens when the recursive function is calling itself and the **recursive call is the very first call** in the function.

- At **call time**, the function doesn't have to process any operations
- Operations are performed only at **return time**
#### Head Recursion vs Loops

- Loops are **more space efficient** than head recursions
- Loops don't call themselves and thus they take only **1 activation record** in the [[stack-memory|Stack]]
- So, it's better to convert head recursions into loops instead
- Both loops and head recursions take the **same amount of time complexity**
#### Code

In `fun2`, the recursive call is the **first operation** executed inside the conditional block:

```cpp
void fun2(int n) 
{
    if (n > 0) 
    {
        fun2(n - 1);
        printf("%d ", n);
    }
}

// Output: 1 2 3
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
#### The Stack

```txt
|===================================|
|  fun2(0) Activation Record        | <- CURRENT TOP OF STACK (n=0: False! Returns 0)
|-----------------------------------|
|  fun2(1) Activation Record (n=1)  | <- Paused at line: printf("%d ", n);
|-----------------------------------|
|  fun2(2) Activation Record (n=2)  | <- Paused at line: printf("%d ", n);
|-----------------------------------|
|  fun2(3) Activation Record (n=3)  | <- Paused at line: printf("%d ", n);
|-----------------------------------|
|  main() Activation Record         | <- Waiting for fun2(3) to finish
|===================================|
              STACK
```
