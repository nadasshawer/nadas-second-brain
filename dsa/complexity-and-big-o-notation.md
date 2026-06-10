## Algorithm Complexity
#### Analysis of Algorithms

The field of study concerned with finding the amount of time, space or other resources required to complete the execution of computer programs.

#### Algorithm Design & Optimization

The process of figuring out **the best algorithm** to solve a given problem.

## Complexity

**Complexity** of an algorithm is a measure of the amount of time and/or space required by an algorithm for an input of a given size (e.g. `N`). 

- Unless otherwise stated, the term _complexity_ always refers to the **worst-case** complexity
- **Example** → the highest possible time/space taken by the program/algorithm to process an input
#### Big O Notation

- The **worst-case complexity** is often expressed using the **Big O notation**
- In the Big O, we drop **fixed constants** and **lower powers** of variables to capture the ==trend of relationship== between the *size of the input* and the *complexity* of the algorithm
- **Example** → if the complexity of the algorithm is `cN^3 + dN^2 + eN + f`, in the Big O notation it is expressed as **O(N^3)**