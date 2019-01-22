//
//  StraightPoker.go
//  Go 
//
//  Created by Inso on 2019/1/22.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer61

import (
	"sort"
)

func StraightPoker(pokers []int) bool {
	if len(pokers) == 0 || len(pokers) > 5	 {
		return false
	}

	sort.Ints(pokers)

	jokerCount := 0
	for _, val := range pokers {
		if val == 0 {
			jokerCount += 1
		}
	}


	gap := 0
	for i := jokerCount; i < len(pokers)-1; i++ {
		if pokers[i+1] == pokers[i] {
			return false
		}
		gap += pokers[i+1] - pokers[i] - 1
	}

	if gap > jokerCount {
		return false
	}

	return true
}