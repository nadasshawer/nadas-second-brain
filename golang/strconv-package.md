## The "strconv" Package

A built-in Go package used to convert **strings** to different data types.
#### Structure

- **It returns 2 things:**
	- the converted value of the string
	- the error (if any)
#### Syntax

- Use `strconv.` followed by the function's name
- **Example** → `fmt.println(strconv.Atoi("23"))` → output is `23 <nil>`
	- `23` → the integer representation of the string `"23"`
	- `<nil>` → the error, `<nil>` means no error occurred
### Common Functions
#### Atoi()

- Converts a string into a number
- Takes only **1** parameter (the string to be converted)

```go
package main

import (
	"fmt"
	"strconv"
)

func main(){
	x, err := strconv.Atoi("23")
	fmt.Println(x, err)       // output: 23 <nil>
	
	y, err := strconv.Atoi("hello")
	fmt.Println(y, err)       // output: 0 strconv.Atoi: parsing "hello": invalid syntax
}
```

#### ParseInt()

- Takes **3** parameters:
	1. String to be converted
	2. Base
	3. Bit size (number of bits this integer will be stored in)
		- Adding `0` uses the default `int64`

```go
func main(){
	x := "123"
	y, err := strconv.ParseInt(x, 10, 64)
	fmt.Println(y, err)       // output: 123 <nil>
	
	x := "1111011"
	y, err := strconv.ParseInt(x, 2, 64)
	fmt.Println(y, err)       // output: 123 <nil>
	
	x := "123"
	y, err := strconv.ParseInt(x, 2, 64)    // can't convert base 10 to base 2 (and vice versa)
	fmt.Println(y, err)       // output: 0 strconv.ParseInt: parsing "123": invalid syntax
}
```