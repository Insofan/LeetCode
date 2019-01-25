//
//  LongNoRepeatSubStr_test.go
//  Go
//
//  Created by Inso on 2019/1/25.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer48

import (
	"testing"
)

func TestLongestNoRepeatSubStr(t *testing.T) {
	str := "arabcacfr"
	res := LongestNoRepeatSubStr(str)
	want := 4
	if res != want {
		t.Error("Offer 48 最长无重复子串 err")
	}
}
