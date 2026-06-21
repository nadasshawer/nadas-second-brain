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
- **Example** → if the complexity of the algorithm is `cN^3 + dN^2 + eN + f`, in the Big O notation it is expressed as **O($n^3$)**
#### Time Complexity

**Time complexity** is a way to measure ==how fast== an algorithm runs as the amount of input data grows.

- **O($1$) → Constant Time**
	- No loops
	- Code executes sequentially in a fixed number of steps, no matter how big the input is
    
- **O($log n$) → Logarithmic Time** 
	- One loop where the variable is **multiplied or divided**
	- The problem size cuts in half each step (like Binary Search)
	- **Ex:** `i = i / 2`
    
- **O($n$) → Linear Time** 
	- One standard loop that steps forward linearly
	- It checks every item exactly once
	- **Ex:** `i++` or `i--`
    
- **O($n^2$) → Quadratic Time**
	- **Nested loops** where both loops depend on the input size and increment linearly
	- **Ex:** a `i++` loop containing a `j++` loop