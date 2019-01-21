//
//  MergeSort_test.go
//  Go
//
//  Created by Inso on 2018/10/8.
//  Copyright © 2018 Inso. All rights reserved.
//

package MergeSort

import (
	"LeetCode/Go/Util"
	"sort"
	"testing"
)

func TestMergeSort(t *testing.T) {

	input := util.RandomArr(10, 50)
	want := input
	sort.Ints(want)

	mergeSort(input, 0, len(input)-1)

	for i, val := range input {
		if val != want[i] {
			t.Error("Bad sort")
		}
	}
}
