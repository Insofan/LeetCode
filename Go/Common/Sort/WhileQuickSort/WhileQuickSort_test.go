//
//  WhileQuickSort_test.go
//  Go 
//
//  Created by Inso on 2019/1/17.
//  Copyright © 2019 Inso. All rights reserved.
//
package WhileQuickSort

import (
	"testing"
)

func TestWhileQuickSort(t *testing.T) {
	params := []int{5, 1, 3, 4, 2}
	ans := []int{1, 2, 3, 4, 5}

	WhileQuickSort(params, 0, len(params)-1)
	for i, val := range params {
		if ans[i] != val {
			t.Error("While quick sort failed")
		}
	}
}