//
//  MinNumInVec_test.go
//  Go
//
//  Created by Inso on 2019/1/28.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer45

import (
	"fmt"
	"testing"
)

func TestMinNumInVec(t *testing.T) {
	arg := []int{3, 32, 321}

	res := MinNumInVec(arg)
	fmt.Println(res)
}
