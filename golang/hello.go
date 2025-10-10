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


type Car struct {
	price float64
	color int
	wheels_count int
}

type Calculator struct {
	op1 int
	op2 int
}
func (cr Calculator) Add() int{
	return cr.op1 + cr.op2
}

type Animal interface{
	speak() 
}
type Dog struct {

}
type Cat struct {

}

func (dog Dog) speak(){
	fmt.Printf("Woof!\n")
}
func (cat Cat) speak(){
	fmt.Printf("Miao~\n")
}
func test(animal Animal){
	animal.speak()
}

func detect(animal Animal){
	switch v:= animal.(type){
	case Dog:
		fmt.Printf("This is a dog!\n")
		v.speak()
	case Cat:
		fmt.Printf("This is a cat!\n")
		v.speak()
	default:
		fmt.Printf("None\n")
	}
}

func main() {
	detect(Dog{})
	detect(Cat{})
	test(Dog{})
	test(Cat{})
	ret1 := Calculator{
		op1 : 34,
		op2 : 82,
	}
	fmt.Printf("%d\n",ret1.Add())
	// a := 1
	// b := 3.1
	str := "woof"
	c, d, e := 23, false,3.14
	fmt.Printf("%d,Type: %T\n",c,c)
	fmt.Printf("%v,Type: %T\n",d,d)
	fmt.Printf("%.2f,Type: %T\n",e,e)
	fmt.Printf(str + "\n")
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
	bench_car := Car{
		price : 89.2,
		wheels_count : 1,
		color : 4,
	}
	// anonymous struct:
	my_car := struct {
		Make string
		Model string
	}{
		Make: "Tesla",
		Model: "Model 3",
	}
	fmt.Printf("%.2f\n",bench_car.price)
	fmt.Printf("%d\n",bench_car.wheels_count)
	fmt.Printf("%d\n",bench_car.color)
	fmt.Printf(my_car.Model + "\n")
	fmt.Printf(my_car.Make + "\n")
}