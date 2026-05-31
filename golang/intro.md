# Basics
##### Go Use Cases

- Cloud and network services
- Command Line Interfaces (CLI)
- Web development
- Automation and DevOps
- Utilities and stand-alone tools
##### Running Go Files
###### Run

- Use the `go run` command to directly execute a file
- The `run` command compiles the code secretly in the background, then outputs the results
###### Build

- Use the `go build` command to first compile the file into machine code (`.exe`)
- Then you can run that `.exe` by typing its name in the terminal (`./demo.exe`)
##### Constraints

- We can't run a file if we have an imported library that is NOT used

---
### Data Types
##### Commonly Used Types

- `int` --> signed integers (defaults to either `int32` or `int64`)
- `uint` --> unsigned integers (defaults to either `uint32` or `uint64`)
- `byte` --> can store numbers or chars (equivalent to `int8`)
- `rune` --> equivalent to `int32`
- `bool` --> either true or false
- `string` --> anything inside double quotes `""`
- `nil` --> undefined or null
##### Explicit vs Implicit Type Assignment

- `var x int = 5` or `var x int` --> explicit
	- only explicitly declare vars when you **don't actually want to assign it a value**

- `x := 5` --> implicit
	- only works when you assign a value to the var
	- use this 90% of the time

---
