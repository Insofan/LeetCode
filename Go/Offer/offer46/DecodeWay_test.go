//
//  DecodeWay_test.go
//  Go
//
//  Created by Inso on 2019/1/28.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer46

import (
	"testing"
)

func TestDecodeWay(t *testing.T) {
	arg := "226"
	res := DecodeWay(arg)
	want := 3
	if res != want {
		t.Error("Offer 46 (leetcode 91) 数字转字符串 error")
	}
}
