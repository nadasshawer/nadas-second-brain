## Head Recursion (Returning)

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