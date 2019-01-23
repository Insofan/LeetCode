//
//  SingleNumber_test.go
//  Go 
//
//  Created by Inso on 2019/1/23.
//  Copyright © 2019 Inso. All rights reserved.
//
package  offer56_01

import "testing"

func TestSingleNum(t *testing.T) {

	arr := []int{1, 1, 2, 2, 6, 4, 4, 5, 5}
	want := 6
	res := SingleNum(arr)

	if want != res {
		t.Error("Offer 56 数字出现次数 01 错误")
	}
}