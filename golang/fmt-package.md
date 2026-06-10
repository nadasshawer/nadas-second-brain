## The "fmt" Package

A built-in library in Go library for implementing formatted **input and output (I/O)**.
#### Syntax

- Use `fmt.` followed by the function's name
- **Example** → `fmt.Printf("Hey there!")` to print text to the console
### Common Functions
#### Printf

- Stands for "**print formatted**"
- Similar to Python's `print(f"...")` and C's `printf()`
- Does **not** add a newline at the end
- To make the next output go on a new line, explicitly type `\n`
- Allows the use of verbs like `%s` or `%d` to insert data into a template string

```go
name := "Nada"
age := 20
fmt.Printf("Name: %s | Age: %d\n", name, age)
fmt.Printf("Next line!")

// === Output ===
// Name: Nada | Age: 20
// Next line!
```
#### Println

- Stands for "**print line**"
- Automatically inserts a space between arguments if neither of them is a string
- **Always** adds a newline character (`\n`) at the very end of the text
- Cannot use format verbs (like `%d` or `%s`) to inject variables into specific places in a string

```go
name := "Nada"
age := 20
fmt.Println("Name:", name, "Age:", age)
fmt.Println("Next line!")

// === Output ===
// Name: Nada Age: 20
// Next line!
```
#### Sprintf

- Creates a string **without** printing it to the console
- Used to store a string in a variable for later use
- **Example** → `y := fmt.Sprintf("%.2f%%", x)`