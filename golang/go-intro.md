## Basics
#### Go Use Cases

- Cloud and network services
- Command Line Interfaces (CLI)
- Web development
- Automation and DevOps
- Utilities and stand-alone tools
#### Running Go Files
##### Run

- Use the `go run` command to directly execute a file
- The `run` command compiles the code secretly in the background, then outputs the results
##### Build

- Use the `go build` command to first compile the file into machine code (`.exe`)
- Then run that `.exe` by typing its name in the terminal (`./demo.exe`)
##### Constraints

- **Cannot run a file** if there is an imported library that is **not** used

---
## Structure of a Go File

Every single runnable Go file we write will always follow this exact top-to-bottom stack:

```go
package main // Tells Go this file is a runnable program, not a shared library

import "fmt" // Pulls in the external "fmt" package from Go's standard library

func main() { // The mandatory entry point function where execution starts
	fmt.Println("Hello, World!")
}
```

#### The fmt Package

- A built-in library in Go's standard library
- Used to implement formatted **input and output (I/O)**
#### The Main Function

- The **entry point** of the program
- Go **always** looks for the `main()` function
- The function needs to be named exactly `main` (case sensitive)

---
## Console Output
#### Printf

- Stands for "print formatted"
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

- Stands for "print line"
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

- Creates a string without printing it to the console
- Used to store a string in a variable for later use
- **Example** → `y := fmt.Sprintf("%.2f%%", x)`

---
## Data Types & Variables
#### Common Data Types

- `int` → signed integers (defaults to either `int32` or `int64`)
- `uint` → unsigned integers (defaults to either `uint32` or `uint64`)
- `byte` → can store numbers or chars (equivalent to `int8`)
- `rune` → equivalent to `int32`
- `bool` → either true or false
- `string` → anything inside double quotes `""`
- `nil` → undefined or null
#### Explicit vs Implicit Type Assignment

- `var x int = 5` or `var x int` → explicit
	- Only explicitly declare variables when you **don't actually want to assign it a value**

- `x := 5` → implicit
	- Only works when a value is assigned to the variable
	- Used 90% of the time
#### Format Verbs

Special placeholder tokens starting with a percent sign (`%`) used within the `fmt` package functions (such as `Printf`, `Sprintf`, and `Fprintf`) to define exactly how a value should be displayed.

```go
package main
import "fmt"

func main(){
	x := 3
	y := 2.4805
	z := "nada"
	
	fmt.Printf("%T", x)		// data type: int
	fmt.Printf("%v", x)		// actual value: 3
	fmt.Printf("%b", x)		// binary value: 11
	fmt.Printf("%e", y)		// scientific notation: 2.480500e+00
	fmt.Printf("%f", y)		// floating point value: 2.480500
	fmt.Printf("%s", z)		// string text: nada
	fmt.Printf("%.2f", y)	// floating percision: 2.48
	fmt.Printf("%10.2f", y)	// width block padded:          2.48
}
```

---
