package main

import "fmt"
func add(a,b int) int{
	return a+b
}
func main() {
	// var str string 
	// var a int8 
	// var b float64
	// a := 1
	// b := 3.1
	// str := "woof"
	// c, d, e := 23, false,3.14
	// fmt.Printf("Type: %T\n",c)
	// fmt.Printf("Type: %T\n",d)
	// fmt.Printf("Type: %T\n",e)
	const name = "byBit"
	const place = "BeiJing"
	msg := fmt.Sprintf("Hello,%s,You are in %s\n",name,place)
	fmt.Printf(msg)
	a := 1
	if a > 0{
		fmt.Printf("greater than 0\n")
	}
}