//
//  ReverseString_test.go
//  Go 
//
//  Created by Inso on 2019/1/23.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer58_01

import (
	"testing"
	"fmt"
)

func TestReverseStr(t *testing.T) {

	str := "Hello, 世界!"
	res := ReverseStr(str)
	fmt.Println(res)
	want := "!界世 ,olleH"
	if res != want {
		t.Error("offer 58 翻转字符串1 错误")
	}
}