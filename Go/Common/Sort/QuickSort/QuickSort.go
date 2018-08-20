package main

import (
	"math/rand"
	"time"
	"fmt"
)

func randArr(len, maxNum int) []int {
	tempArr := []int{}
	rand.Seed(time.Now().Unix())
	for i := 0; i < len; i++ {
		x := rand.Intn(maxNum)
		tempArr = append(tempArr, x)
	}
	return tempArr
}

func quickSort(arr []int, left, right int) {
	if (left < right) {
		key := partition(arr, left, right)
		quickSort(arr, left, key-1)
		quickSort(arr, key+1, right)
	}
}

func partition(arr []int, left, right int) int {
	pivot := arr[right]
	j := left - 1
	for i := left; i <= right; i++ {
		if (arr[i] < pivot) {
			j++;
			arr[j], arr[i] = arr[i], arr[j]
		}
	}

	arr[j+1], arr[right] = arr[right], arr[j+1]
	return j + 1

}
func main() {
	arr := randArr(10, 50)
	for _, val := range arr {
		fmt.Printf("%d ", val)
	}
	fmt.Println()
	quickSort(arr, 0, len(arr)- 1)
	for _, val := range arr {
		fmt.Printf("%d ", val)
	}
	fmt.Println()
}
