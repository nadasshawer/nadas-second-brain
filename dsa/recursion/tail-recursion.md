## Tail Recursion (Calling)

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