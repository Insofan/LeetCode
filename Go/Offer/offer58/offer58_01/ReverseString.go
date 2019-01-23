//
//  ReverseString.go
//  Go 
//
//  Created by Inso on 2019/1/23.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer58_01

func ReverseStr(str string) string {
	ru := []rune(str)

	for l, r := 0, len(ru) -1;  l < r; l , r = l + 1, r - 1 {
		ru[l] , ru[r] = ru[r], ru[l]
	}

	return string(ru)
}
