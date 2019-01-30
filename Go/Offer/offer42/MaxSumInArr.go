//
//  MaxSumInArr.go
//  Go
//
//  Created by Inso on 2019/1/30.
//  Copyright © 2019 Inso. All rights reserved.
//

// Package offer42 ...
package offer42

// MaxSumInArr ...
func MaxSumInArr(arr []int) int {
	arrLen := len(arr)
	if arrLen == 0 {
		return -1
	}

	dp := make([]int, arrLen)

	dp[0] = arr[0]

	res := -100000
	for i := 1; i < arrLen; i++ {
		dp[i] = max(dp[i-1]+arr[i], arr[i])
		if dp[i] > res {
			res = dp[i]
		}
	}

	return res
}

func max(x, y int) int {

	if x > y {
		return x
	}
	return y
}
