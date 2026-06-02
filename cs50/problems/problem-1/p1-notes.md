## Catches

### Dynamic String Representation
#### Problem

-  In C, we can't just perform dynamic string representation like in Python and some other languages
 * A char (e.g. `"#"`) in C is stored in memory as `'#'` and `'\0'`
 * When we use it in an expression, it evaluates to the char's **memory address (a pointer)**, not the char's actual value!
 
So, when we try to multiply `"#"` by an integer like `3`, the compiler is trying to multiply the hexadecimal value of that pointer, so it crashes and throws a compilation error.

```c
for(int i = 1; i < height + 1; i++){
    printf("#" * i);      // will throw an error
}
```
#### Solution

Since C doesn't have built-in string multiplication, we have to **explicitly loop** to print it multiple times

```c
for(int i = 1; i < height + 1; i++){
    printf("#" * i);      // will throw an error
}
```