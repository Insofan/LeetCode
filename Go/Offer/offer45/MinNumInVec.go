//
//  MinNumInVec.go
//  Go
//
//  Created by Inso on 2019/1/28.
//  Copyright © 2019 Inso. All rights reserved.

// Package offer45 ...
package offer45

import (
	"sort"
	"strconv"
)

// MinNumInVec ...
func MinNumInVec(vec []int) string {
	if len(vec) == 0 {
		return "0"
	}

	resSize := 0
	bv := make(btVec, len(vec))
	for i := 0; i < len(vec); i++ {
		bv[i] = []byte(strconv.Itoa(vec[i]))
		resSize += len(bv[i])
	}

	sort.Sort(bv)

	res := make([]byte, 0, resSize)
	for i := len(vec) - 1; i >= 0; i-- {
		res = append(res, bv[i]...)
	}
	i := 0

	for i < resSize-1 && res[i] == '0' {
		i++
	}

	return string(res[i:])
}

type btVec [][]byte

func (bv btVec) Len() int {
	return len(bv)
}

func (bv btVec) Less(i, j int) bool {
	size := len(bv[i]) + len(bv[j])
	bij := make([]byte, 0, size)
	bij = append(bij, bv[i]...)
	bij = append(bij, bv[j]...)

	bji := make([]byte, 0, size)
	bji = append(bji, bv[j]...)
	bji = append(bji, bv[i]...)

	for k := 0; k < size; k++ {
		if bij[k] < bji[k] {
			return true
		} else if bij[k] > bji[k] {
			return false
		}
	}
	return false
}

func (bv btVec) Swap(i, j int) {
	bv[i], bv[j] = bv[j], bv[i]
}
