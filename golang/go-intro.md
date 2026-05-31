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
- Then you can run that `.exe` by typing its name in the terminal (`./demo.exe`)
##### Constraints

- We **can't run a file** if we have an imported library that is **not** used

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

- A built-in library in Go's standard library used to **implement formatted input and output (I/O)**
#### The Main Function

- The **entry point** of the program
- Go **always** looks for the `main()` function, so it needs to be named exactly `main` (case sensitive)

---
## Console Output
#### Printf

- Stands for "print formatted"
- Similar to Python's `print(f"...")` and C's `printf()`
- It does **not** add a newline at the end
- If you want the next output to go to a new line, you must explicitly type `\n`
- You can use verbs like `%s` or `%d` to insert data into a template string
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
- **Always** adds a newline character (`\n`) at the very end of the text, so the next print statement starts on a fresh line
- You cannot use format verbs (like `%d` or `%s`) to inject variables into specific places in a string
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

- Creates a sting but will **not** print it to the console
- Used when you want to create a string and store in some type of variable to use it later, maybe in a function
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
	- only explicitly declare variables when you **don't actually want to assign it a value**

- `x := 5` → implicit
	- only works when you assign a value to the variable
	- use this 90% of the time
#### Format Verbs
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

- Use `%T` for a variable's type
	- **Example** → `Printf("%T", x)` prints the type of `x`, in this case `int`

- Use `%v` for a variable's actual value
	- **Example** → `Printf("%v", x)` prints the value of  `x`, in this case `3`

- Use `%b` for a variable's binary representation
	- **Example** → `Printf("%b", x)` prints the binary value of  `x`, in this case `11`

- Use `%e` for a variable's scientific notation representation
	- **Example** → `Printf("%e", y)` prints the scientific notation of  `y`, in this case `2.480500e+00`

- Use `%f` for a variable's floating point representation
	- **Example** → `Printf("%f", y)` prints the floating point value of  `y`, in this case `2.480500`

- Use `%s` for a variable's string representation
	- **Example** → `Printf("%s", z)` prints the string value of  `z`, in this case `nada`

- Use `%.2f` for getting the value of a variable rounded to a specific number of decimal digits (precision)
	- **Example** → `Printf("%.2f", y)` prints the value of  `y` rounded to 2 decimal digits, in this case `2.48`

- Use `%10.2f` for getting rounded value (as in the example above) but the _entire width_ of the output block will be exactly 10 characters wide, padded with spaces on the left
	- **Example** → `Printf("%10.2f", y)` prints the value of  `y` rounded to 2 decimal digits and padded 10 digits to the left, in this case `          2.48`


---
