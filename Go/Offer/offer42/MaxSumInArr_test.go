//
//  MaxSumInArr_test.go
//  Go
//
//  Created by Inso on 2019/1/30.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer42

import (
	"testing"
)

func TestMaxSumInArr(t *testing.T) {

	args := []int{1, -2, 3, 10, -4, 7, 2, -5}

	res := MaxSumInArr(args)
	want := 18
	if res != want {
		t.Error("Offer 42 error")
	}
}
