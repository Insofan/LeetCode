//
//  ReverseString_test.go
//  Go 
//
//  Created by Inso on 2019/1/23.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer58_02

import (
	"testing"
)

func TestReverse(t *testing.T) {
	str := "abcdefg"
	res := Reverse(str, 2)
	want :=  "cdefgab"
	if res != want {
		t.Error("offer 59 02 左旋字符串错误")
	}

}