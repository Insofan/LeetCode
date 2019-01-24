package main

import (
	"fmt"
	"math/rand"
	"time"
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

func selectionSort(arr []int) {
	for i := range arr {
		key := i
		for j := i + 1; j < len(arr); j++ {
			if arr[j] < arr[key] {
				key = j
			}
		}
		arr[i], arr[key] = arr[key], arr[i]
	}
}

func main() {
	arr := randomArr(10, 50)
	for _, val := range arr {
		fmt.Printf("%d ", val)
	}
	fmt.Println()
	selectionSort(arr)
	for _, val := range arr {
		fmt.Printf("%d ", val)
	}
}
