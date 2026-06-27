## Tail Recursion (Calling)

**Tail recursion** happens when the recursive function is calling itself and the **recursive call is the very last call** in the function.

- No operations are performed at **return time**
- At **return time**, the function doesn't have to perform any operations at all
#### Tail Recursion vs Loops

- Loops are **more space efficient** than tail recursions
- Loops don't call themselves and thus they take only **1 activation record** in the [[stack-memory|Stack]]
- So, it's better to convert tail recursions into loops instead
- Both loops and tail recursions take the **same amount of time complexity**
#### Code

In `fun1`, the recursive call is the **very last operation** executed in the function:

```cpp
void fun1(int n) 
{
    if (n > 0) 
    {
        printf("%d ", n);
        fun1(n - 1);         // recursive function
    }
}

// Output: 3 2 1
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
#### The Stack

```txt
|===================================|
|  fun1(0) Activation Record        | <- CURRENT TOP OF STACK (n=0: False! Returns 0)
|-----------------------------------|
|  fun1(1) Activation Record (n=1)  | <- Completely done! Just waiting to return.
|-----------------------------------|
|  fun1(2) Activation Record (n=2)  | <- Completely done! Just waiting to return.
|-----------------------------------|
|  fun1(3) Activation Record (n=3)  | <- Completely done! Just waiting to return.
|-----------------------------------|
|  main() Activation Record         | <- Waiting for fun1(3) to finish
|===================================|
              STACK
```
