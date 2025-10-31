package main

import (
	"fmt"
	// "github.com/byBit-ovo/strings"		//module name
	"time"
)
func ThreadEntry(){
	for a:=0;a < 5;a++{
		fmt.Println(a)
		time.Sleep(time.Second)
	}
}

var num = 1
type Number interface{
	~int | ~float64 | ~string
}
func Add[T Number](a,b T) T{
	return a+b
}
func main() {
	fmt.Println(Add(1,2))
	fmt.Println(Add(1.1,2.2))
	fmt.Println(Add("hel","lo"))
	// nums := []int{1,2,3,4,5}
	// preNum := nums[:3]
	// afNum := nums[3:]
	// fmt.Println(preNum,afNum,nums)
	// newNum := append(preNum,9)
	// fmt.Println(preNum,afNum,nums,newNum)
	// fmt.Printf("%v,%v",&nums[0],&newNum[0])

	// arr := make([]int,5,10)
	// arr2 := append(arr,1)
	// fmt.Println(arr)
	// fmt.Println(arr2)
	// fmt.Println(num)
	
	// go ThreadEntry()
	// time.Sleep(time.Second * 10)
	// fmt.Println(1)
	// a := 1
	// pa := &a
	// fmt.Println(*pa)
	// testRAII(1)
	// testRAII(0)
	// testRAII(2)
	// fmt.Println(aggregate(1,4,8,add))

	// ages := make(map[string]int)
	// ages["Tom"] = 12
	// ages["Jack"] = 8
	// ages["uuoo"] += 3
	// fmt.Println(ages["uuoo"])
	// hobby := map[string]string{
	// 	"Jerry": "cheese",
	// 	"Tom": "Jerry",
	// }
	// for key,value:= range hobby{
	// 	fmt.Println(key,":",value)
	// }
	// key1, ok1 := hobby["Jerry"]
	// key2, ok2 := hobby["T"]
	// fmt.Println(key1,ok1)
	// fmt.Println(key2,ok2)
	//vector<vector<int>>
	// matrix := [][]int{}
	// matrix = append(matrix,[]int{1,2,3})
	// matrix = append(matrix,[]int{1,2})
	// matrix = append(matrix,[]int{1})
	// fmt.Println(matrix)
	// for row, ele := range matrix{
	// 	fmt.Println(row,ele)
	// }
	// b := [3]int{}
	// a := b[:]
	// a = append(a,a...)
	// fmt.Println(a)
	// matrix := [][]int

	// arr := [5]int{1, 2, 3, 4, 5}
	// s1 := arr[1:3]
	// s2 := s1 // 拷贝切片结构体（三个字段）

	// s2[0] = 100
	// fmt.Println(s1) // [100 3]
	// fmt.Println(arr) // [1 100 3 4 5]

	// arr := [10]int {1,3,4,5,6,7,82}
	// arr2 := arr[1:6]
	// arr2[0] = -1
	// fmt.Println(arr)
	// fmt.Println(arr2)
	// fmt.Println(1,2,3)
	// fmt.Printf("\n")
	// for a:=0;a<11;a=a+1{
	// 	fmt.Printf("%d ",a)
	// }
	// fmt.Printf("\n")
	// detect(Dog{})
	// detect(Cat{})
	// test(Dog{})
	// test(Cat{})
	// ret1 := Calculator{
	// 	op1 : 34,
	// 	op2 : 82,
	// }
	// fmt.Printf("%d\n",ret1.Add())
	// // a := 1
	// // b := 3.1
	// str := "woof"
	// c, d, e := 23, false,3.14
	// fmt.Printf("%d,Type: %T\n",c,c)
	// fmt.Printf("%v,Type: %T\n",d,d)
	// fmt.Printf("%.2f,Type: %T\n",e,e)
	// fmt.Printf(str + "\n")
	// const name = "byBit"
	// const place = "BeiJing"
	// msg := fmt.Sprintf("Hello,%s,You are in %s\n",name,place)
	// fmt.Printf(msg)
	
	// if a := 1 ; a < 0{
	// 	fmt.Printf("greater than 0\n")
	// }else{
	// 	fmt.Printf("%d\n",a)
	// }

	// fmt.Printf(concat("former, ","latter\n"))
	// x,y,z := yearsUntilEvents(20)
	// fmt.Printf("%d,%d,%d\n",x,y,z)
	// bench_car := Car{
	// 	price : 89.2,
	// 	wheels_count : 1,
	// 	color : 4,
	// }
	// // anonymous struct:
	// my_car := struct {
	// 	Make string
	// 	Model string
	// }{
	// 	Make: "Tesla",
	// 	Model: "Model 3",
	// }
	// fmt.Printf("%.2f\n",bench_car.price)
	// fmt.Printf("%d\n",bench_car.wheels_count)
	// fmt.Printf("%d\n",bench_car.color)
	// fmt.Printf(my_car.Model + "\n")
	// fmt.Printf(my_car.Make + "\n")
}
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

func sumFunc(nums ...int) int{
	sum := 0
	for i:=0;i<len(nums);i++{
		sum += nums[i]
	}
	return sum
}
func createMatrix(r, c int) [][]int{
	matrix := make([][]int,0)
	for i:=0;i<r;i++{
		matrix = append(matrix, []int{})
		for j:=0;j<c;j++{
			matrix[i] = append(matrix[i], i*j)
		}
	}
	return matrix
}


func aggregate(a,b,c int, calculate func(int, int) int ) int{
	return calculate(calculate(a,b),c)
}
func testRAII(num int){
	defer fmt.Println("hello")
	if num == 0{
		return
	}
}