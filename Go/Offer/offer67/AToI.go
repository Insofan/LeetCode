//
//  AToI.go
//  Go
//
//  Created by Inso on 2019/1/24.
//  Copyright © 2019 Inso. All rights reserved.
//  开始导入 gometalinter

// Package offer67 wtf
package offer67

const intMax = (2 << 31) - 1
const intMin = -(2 << 30)

// AToI 字符串转数字
func AToI(str string) int {
	ru := []rune(str)
	i := 0
	sign := 1
	base := 0

	for ru[i] == ' ' {
		i++
	}

	if ru[i] == '-' {
		sign = -1
		i++
	} else if ru[i] == '+' {
		sign = 1
		i++
	}

	for i < len(str) && ru[i] >= '0' && ru[i] <= '9' {
		// 判断溢出
		// 第一个判断 如果大于intMax / 10 那么加一位肯定溢出
		// 第二个判断  base== INT_MAX/10, that means all the places are the same as INT_MAX except the ones place, so str[i]>‘7’ is needed , 只要末尾是大于7的相当于*10和intMAX一个数量级但是末尾大于7肯定已经溢出了, 因为32位的是2147483647
		if (base > intMax/10) || (base == intMax/10 && ru[i]-'0' > 7) {
			// 溢出时返回负或者正 max
			if sign == 1 {
				return intMax
			}
			return intMin
		}
		base = base*10 + int(ru[i]-'0')
		i++
	}

	return sign * base
}
