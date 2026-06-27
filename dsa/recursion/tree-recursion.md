## Tree Recursion

**Tree recursion** happens when a recursive function is calling itself **more than 1 time**.
#### Code

```cpp
void fun(int n) {
    if (n > 0) {
        printf("%d ", n);
        fun(n - 1);
        fun(n - 1);
    }
}

// Output: 3 2 1 1 2 1 1
// Time: O(2^n)
// Space: O(n)
```
#### Recursive Tree

```txt
                 fun(3) [Prints 3]
                     /      \
        [Left]      /        \      [Right]
                   /          \
         fun(2) [Prints 2]      fun(2) [Prints 2]
          /      \               /      \
         /        \             /        \
   fun(1) [Pr 1]  fun(1) [Pr 1] ...etc   ...etc
    /    \         /    \
 fun(0)  fun(0) fun(0)  fun(0)
```
#### The Stack

```txt
|===================================|
|  fun(0) Activation Record         | <- CURRENT TOP OF STACK (n=0: False! Returns instantly)
|-----------------------------------|
|  fun(1) Activation Record (n=1)   | <- Paused! Just finished 1st call; waiting for 2nd fun(n-1)
|-----------------------------------|
|  fun(2) Activation Record (n=2)   | <- Paused! Waiting for its 1st left-side fun(n-1) to finish
|-----------------------------------|
|  fun(3) Activation Record (n=3)   | <- Paused! Waiting for its 1st left-side fun(n-1) to finish
|-----------------------------------|
|  main() Activation Record         | <- Waiting for fun(3) to return
|===================================|
               STACK
```
