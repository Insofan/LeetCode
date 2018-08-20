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
	for i := 0; i < len(arr); i++ {
		key := arr[i]
		j := i - 1
		for j >= 0 && arr[j] > key {
			arr[j+1] = arr[j]
			j--
		}
		arr[j + 1] = key
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
