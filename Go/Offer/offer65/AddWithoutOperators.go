//
//  AddWithOperator.go
//  Go
//
//  Created by Inso on 2019/1/21.
//  Copyright © 2019 Inso. All rights reserved.
//

package offer65

/*!
题目: 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/
func AddWithOutOpers(a, b int) int {
	if b == 0 {
		return a
	} else {
		return AddWithOutOpers(a^b, a&b<<1)
	}
}
