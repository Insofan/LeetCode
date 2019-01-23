//
//  ReversStringII.go
//  Go 
//
//  Created by Inso on 2019/1/23.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer58_02
/*!
	字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数字2，该函数将返回左旋转2位得到的结果"cdefgab"。
 */

func Reverse(str string, idx int) string {
	ru := []rune(str)

	for l, r := 0, idx-1; l < r; l, r = l+1, r-1 {
		ru[l], ru[r] = ru[r], ru[l]
	}

	for l, r := idx, len(ru) - 1; l < r; l, r = l+1, r-1 {
		ru[l], ru[r] = ru[r], ru[l]
	}

	for l, r := 0, len(ru) - 1; l < r; l, r = l+1, r-1 {
		ru[l], ru[r] = ru[r], ru[l]
	}

	return string(ru)
}

