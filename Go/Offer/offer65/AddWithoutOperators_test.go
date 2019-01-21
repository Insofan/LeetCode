//
//  AddWithoutOperators_test.go
//  Go
//
//  Created by Inso on 2019/1/21.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer65

import (
	"fmt"
	"testing"
)

func TestAddWithOutOpers(t *testing.T) {
	input := []int{1, 2}
	ans := AddWithOutOpers(input[0], input[1])
	fmt.Printf("Input %v add %v \n", input[0], input[1])
	want := input[0] + input[1]

	fmt.Println("Ans is ", ans)
	if ans != want {
		t.Error("Add nums err")
	}
}
