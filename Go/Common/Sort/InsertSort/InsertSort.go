package main

import "time"
import (
	"math/rand"
	"fmt"
)

func randomArr(len, maxNum int) []int {
	tempArr := []int{}
	rand.Seed(time.Now().Unix())

	for i := 0; i < len; i++ {
		x := rand.Intn(maxNum)
		tempArr = append(tempArr, x)
	}
	return tempArr
}

func insertSort(arr []int) {
	for i := 1; i < len(arr); i++ {
		insertNum := arr[i]
		j := i
		for j > 0 &&  insertNum < arr[j - 1]  {
			arr[j] = arr[j - 1];
			j--
		}
		arr[j] = insertNum
	}
}

func main() {
	arr := randomArr(10, 100)

	for _, val := range arr {
		fmt.Printf("%d ", val)
	}

	fmt.Println()

	insertSort(arr)
	for _, val := range arr {
		fmt.Printf("%d ", val)
	}
}
