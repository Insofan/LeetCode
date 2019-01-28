//
//  DecodeWa.go
//  Go
//
//  Created by Inso on 2019/1/28.
//  Copyright © 2019 Inso. All rights reserved.
//

// Package offer46 wtf
package offer46

// DecodeWay leetcode 91题
func DecodeWay(str string) int {
	if len(str) == 0 {
		return 0
	}

	ru := []rune(str)
	dp := make([]int, len(ru)+1)
	dp[len(ru)] = 1
	for i := len(ru) - 1; i >= 0; i-- {
		if ru[i] == '0' {
			dp[i] = 0
		} else {
			dp[i] = dp[i+1]
			if (i < len(ru)-1) && (ru[i] == '1' || ru[i] == '2') && ru[i+1] < '7' {
				dp[i] += dp[i+2]
			}
		}
	}

	return dp[0]
}
