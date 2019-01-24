//
//  AToI_test.go
//  Go
//
//  Created by Inso on 2019/1/24.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer67

import (
	"testing"
)

func TestAToI(t *testing.T) {

	args := []string{
		"   -42",
		"4193 with words",
		"words and 987",
		"-91283472332",
	}

	want := []int{
		-42,
		4193,
		0,
		-2147483648,
	}

	var res []int

	for _, val := range args {
		res = append(res, AToI(val))
		//fmt.Println("res : ", res)
	}

	for i, val := range res {
		if val != want[i] {
			t.Error("Offer 67 字符串转数字 err res ", val, " want ", want[i])
		}
	}
}
