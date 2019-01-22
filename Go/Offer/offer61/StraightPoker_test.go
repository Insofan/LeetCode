//
//  StraightPoker_test.go
//  Go 
//
//  Created by Inso on 2019/1/22.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer61

import (
	"testing"
	"fmt"
)

func TestStraightPoker(t *testing.T) {
	//arr := []int{5,7,6,0,4}
	arr := []int{0, 3, 1, 6, 4}

	res := StraightPoker(arr)
	fmt.Println(res)

	want := true

	if res != want {
		t.Error("straight poker err")
	}
}