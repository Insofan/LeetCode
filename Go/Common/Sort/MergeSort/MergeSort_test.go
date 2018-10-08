//
//  MergeSort_test.go
//  Go 
//
//  Created by Inso on 2018/10/8.
//  Copyright © 2018 Inso. All rights reserved.
//

package MergeSort

import "testing"

func TestMergeSort(t *testing.T) {

	input := []int{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
	want := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

	MergeSort(input, 0, len(input) - 1)

	for i, val := range input {
		if val != want[i] {
			t.Error("Bad sort")
		}
	}
}
