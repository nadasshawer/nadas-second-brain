## Heap Memory

The **Heap** is just **one specific section** of the Main Memory (RAM). It's the region of memory reserved for **dynamic allocation**. 

Unlike other parts of memory (like the Stack, which automatically grows and shrinks as functions are called), the Heap is a giant, unorganized pool of **free memory**. The computer program can't access Heap memory directly, it can only be accessed via a **pointer**.
#### Deallocation

- Whenever we're dynamically allocating memory, the memory must be released when we've finished using it
- Heap memory should be treated as a **resource**
- Heap memory should be explicitly requested and explicitly released
- Failing to release unused memory in the Heap will result in a **loss of memory** → [memory leak](memory-leak)
#### Advantages

When allocating memory in heap, we get 3 major advantages:
1. The size can change at runtime (dynamic sizing)
2. The variables survive outside the function
3. Avoiding stack overflow