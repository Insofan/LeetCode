//
//  CountSmallerOfSelf_test.go
//  Go
//
//  Created by Inso on 2019/1/25.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer51

import "testing"

func TestCountSmallerOfSelf(t *testing.T) {
	arr := []int{5, 2, 6, 1}
	want := []int{2, 1, 1, 0}
	res := CountSmallerOfSelf(arr)

	for i, val := range res {
		if want[i] != val {
			t.Error("Offer 51 逆序对错误")
		}
	}
}
