## Padding

**Padding** is the insertion of "empty" or "wasted" bytes between variables in memory by the compiler to ensure that everything aligns perfectly with the processor's word boundaries.
#### Example

```cpp
struct MyStruct 
{
    char a;   // takes 1 byte
    int b;    // takes 4 bytes
};

int main
{
	cout << sizeof(MyStruct);    // 8
}
```

- The compiler looks at the 4-byte integer `b` and says, _"I want this integer to start at a memory address that is a multiple of 4"_ 
- Since `char a` only took up byte 0, the compiler intentionally leaves bytes 1, 2, and 3 completely empty
- It sticks `b` at byte 4
#### Why Care?
| **Bad Struct Layout (More Padding)**                                                                                                    | **Optimized Struct Layout (Less Padding)**                                                                           |
| --------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------- |
| `struct Bad { char a; // 1 byte // 3 bytes padding int b; // 4 bytes char c; // 1 byte // 3 bytes padding }; // Total Size = 12 bytes!` | `struct Good { int b; // 4 bytes char a; // 1 byte char c; // 1 byte // 2 bytes padding }; // Total Size = 8 bytes!` |
