//
//  MinNumInVec.go
//  Go
//
//  Created by Inso on 2019/1/28.
//  Copyright © 2019 Inso. All rights reserved.

// Package offer45 ...
package offer45

import (
	"fmt"
)

// MinNumInVec ...
func MinNumInVec(vec []int) int {
	if len(vec) == 0 {
		return 0
	}

	ru := make([]rune, len(vec))
	for i := 0; i < len(vec); i++ {
		ru[i] = rune(vec[i])
	}

	fmt.Println(ru)
	if ru[1]+ru[2] < ru[2]+ru[1] {
		fmt.Println(ru[1], ru[2])
	} else {
		fmt.Println(ru[2], ru[1])
	}
	//sort.Sort(btVec(ru))
	fmt.Println(ru)
	return -1
}

type btVec [][]byte

func (bv btVec) Len() int {
	return len(bv)
}

func (bv btVec) Less(i, j int) bool {
	size := len(bv[i]) + len(bv[j])
}

func (bv btVec) Swap(i, j int) {
	bv[i], bv[j] = bv[j], bv[i]
}
