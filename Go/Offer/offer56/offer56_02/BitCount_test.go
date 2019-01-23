//
//  BitCount_test.go
//  Go 
//
//  Created by Inso on 2019/1/23.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer56_02

import "testing"

func TestBitCount(t *testing.T) {

	args := []int{1, 2, 5, 7, 8}
	want := []int{1, 1, 2, 3, 1}
	for i, val := range want {
		if val != BitCount(args[i]) {
			t.Error("Offer 56 02 二进制中1的个数错误")
		}
	}
}

