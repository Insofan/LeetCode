//  SingleNumber.go
//  Go
//
//  Created by Inso on 2019/1/23.
//  Copyright © 2019 Inso. All rights reserved.
// Package offer56_01 ...
package offer56_01

/*!
数组中除了一个数出现一次, 剩下都出现两次, 找出这个数字
*/

// SingleNum ...
func SingleNum(vec []int) int {

	res := 0

	for _, val := range vec {
		res ^= val
	}

	return res
}
