## Basics
#### Go Use Cases

- Cloud and network services
- Command Line Interfaces (CLI)
- Web development
- Automation and DevOps
- Utilities and stand-alone tools
### Running Go Files
#### Run

- Use the `go run` command to directly execute a file
- The `run` command compiles the code secretly in the background, then outputs the results
#### Build

- Use the `go build` command to first compile the file into machine code (`.exe`)
- Then run that `.exe` by typing its name in the terminal (`./demo.exe`)
#### Constraints

- **Cannot run a file** if there is an imported library that is **not** used
#### Console Output

- The [[fmt-package|"fmt" Package]] is used to print output to the console

## Structure of a Go File

Every single runnable Go file we write will always follow this exact top-to-bottom stack:

```go
package main // Tells Go this file is a runnable program, not a shared library

import "fmt" // Pulls in the external "fmt" package from Go's standard library

func main() { // The mandatory entry point function where execution starts
	fmt.Println("Hello, World!")
}
```
#### The Main Function

- The **entry point** of the program
- Go **always** looks for the `main()` function
- The function needs to be named exactly `main` (case sensitive)

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

- `var x int = 5` or `var x int` → **explicit**
	- Only explicitly declare variables when you **don't actually want to assign it a value**

- `x := 5` → **implicit**
	- Only works when a value is assigned to the variable
	- Used 90% of the time
#### Combining Strings With Variables

- Use [[format-verbs|format verbs]] to inject variables into formatted strings
- Works similar to Pythons fstring (`print(f"Some text and a {variable}!")`)
#### Converting Different Data Types

- Different Go libraries can be used to convert to different data types
- Use the [[strconv-package|strconv library]] to convert **strings** to different data types

## Arithmetic Operators

- Go contains the same basic operators like JS (`+`, `-`, `*` , `/` , `--`, `++`)
- It does **not** contain an exponent operator (`**`)
	- Use the [[math-package#The Power Function|pow function]]
- The type you get *out* is always the **same** as the type you put *in*
#### Constraints

- Values must be of the **same unit** in order to be able to perform arithmetic operations
- When converting between data types, always convert the smaller type into the bigger type
	- **Example** → `unit32` to `unit64`, **not** `unit64` to `unit32`
	- This avoids "weird" results because it preserves the value of the variable without trimming any bits in an *overflow*
#### Packages

- The [[math-package|"math" package]] can be used to perform advanced mathematical operations

## Conditionals

- 