## Format Verbs

Special placeholder tokens starting with a percent sign (`%`) used within the `fmt` package functions (such as `Printf`, `Sprintf`, and `Fprintf`) to define exactly how a value should be displayed.
#### Common Format Verbs

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