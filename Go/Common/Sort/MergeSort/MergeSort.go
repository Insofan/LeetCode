//
//  MergeSort.go
//  Go 
//
//  Created by Inso on 2018/10/8.
//  Copyright © 2018 Inso. All rights reserved.
//
package MergeSort

import (
	"math"
)

func MergeSort(vec []int, left, right int) {
	if (left < right) {
		var mid int = (left + right) / 2
		MergeSort(vec, left, mid)
		MergeSort(vec, mid+1, right)
		partition(vec, left, mid, right)
	}
}

func partition(vec []int, left, mid, right int) {

	len1 := mid - left + 1
	len2 := right - mid

	vec1 := make([]int, len1)
	vec2 := make([]int, len2)

	for i := 0; i < len1; i++ {
		vec1[i] = vec[left + i];
	}

	for i := 0; i < len2; i++ {
		vec2[i] = vec[mid + 1 + i];
	}

	vec1 = append(vec1, math.MaxInt32)
	vec2 = append(vec2, math.MaxInt32)

	k, l := 0, 0

	for i := left; i <= right; i++ {
		if (vec1[k] < vec2[l]) {
			vec[i] = vec1[k]
			k++
		} else {
			vec[i] = vec2[l]
			l++
		}
	}
}

