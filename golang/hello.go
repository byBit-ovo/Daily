package main

import "fmt"
func add(a,b int) int{
	return a+b
}
func concat(s1 string, s2 string) string{
	return s1 + s2
}

func yearsUntilEvents(age int) (int,int,int){
	a := 18 - age
	if a < 0{
		a = 0
	}
	b := 20 - age
	if b < 0{
		b = 0
	}
	c := 25 - age
	if c < 0{
		c = 0
	}
	return a, b, c
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
	
	if a := 1 ; a < 0{
		fmt.Printf("greater than 0\n")
	}else{
		fmt.Printf("%d\n",a)
	}

	fmt.Printf(concat("former, ","latter\n"))
	x,y,z := yearsUntilEvents(20)
	fmt.Printf("%d,%d,%d\n",x,y,z)

}