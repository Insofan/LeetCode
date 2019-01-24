//
// CharCountInSortedArr.go
// Go
//
// Created by Inso on 2019/1/23.
// Copyright © 2019 Inso. All rights reserved.

// Package offer53 ...
package offer53

import "fmt"

// CountInSortedArr ...
func CountInSortedArr(vec []int, tar int) int {

	firIdx := indexInArr(vec, tar)
	fmt.Println("fir : ", firIdx)
	secIdx := indexInArr(vec, tar+1)
	fmt.Println("sec : ", secIdx)

	if firIdx >= 0 && firIdx < len(vec)-1 && secIdx-1 >= 0 && secIdx-1 < len(vec)-1 {
		return secIdx - firIdx
	}

	return -1
}

func indexInArr(vec []int, tar int) int {

	l := 0
	r := len(vec) - 1
	for l <= r {
		mid := (r + l) / 2
		if vec[mid] < tar {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}

	return l
}
