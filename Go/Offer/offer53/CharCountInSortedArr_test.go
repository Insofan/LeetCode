//
//  CharCountInSortedArr_test.go
//  Go 
//
//  Created by Inso on 2019/1/23.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer53

import (
	"testing"
	"fmt"
)

func TestCountInSortedArr(t *testing.T) {

	vec := []int{1,2,3,3,3,3,4,5}
	tar := 3
	want := 4
	res := CountInSortedArr(vec, tar)
	fmt.Println(res)

	if res != want {
		t.Error("Offer 56 排序数组中出现次数 err")
	}
}