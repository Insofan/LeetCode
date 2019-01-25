//
//  LongNoRepeatSubStr.go
//  Go
//
//  Created by Inso on 2019/1/25.
//  Copyright © 2019 Inso. All rights reserved.

// Package offer48 最长无重复连续子串, bad
package offer48

// LongestNoRepeatSubStr 最长不重复子串
func LongestNoRepeatSubStr(str string) int {
	//”arabcacfr”， "rabc"或者"acfr"

	mySet := map[rune]bool{}

	res := 0

	for i, j := 0, 0; i < len(str); {
		if _, ok := mySet[rune(str[i])]; ok {
			delete(mySet, rune(str[j]))
			j++
		} else {
			mySet[rune(str[i])] = true
			i++
		}

		if len(mySet) > res {
			res = len(mySet)
		}
	}
	return res
}
