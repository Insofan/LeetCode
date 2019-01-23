//
//  BitCount.go
//  Go 
//
//  Created by Inso on 2019/1/23.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer56_02

/*!
	一个数二进制表示法中1的个数
 */
func BitCount(num int) int {

	res := 0
	for num > 0 {
		num &= num - 1
		res++
	}

	return res
}