//
//  MaxinumDepthOfBinaryTree.go
//  Go 
//
//  Created by Inso on 2018/8/20.
//  Copyright © 2018 Inso. All rights reserved.
//
package main

import (
	"fmt"
)
import (
	"../../Util"
)

func maxNum(x, y int) int {
	if ( x >y) {
		return x
	} else {
		return y
	}
}
func maxDepth(root *util.TreeNode) int {
	var ld int = 0
	var rd int = 0
	if (root == nil){
		return 0
	} else {
		ld = maxDepth(root.Left)
		rd = maxDepth(root.Right)
		return maxNum(ld, rd) + 1
	}
}

func main() {
	a := util.TreeNode{3, nil, nil}
	b := util.TreeNode{9, nil, nil}
	c := util.TreeNode{20, nil, nil}
	d := util.TreeNode{15, nil, nil}
	e := util.TreeNode{7, nil, nil}

	a.Left = &b
	a.Right = &c
	c.Left = &d
	c.Right = &e

	var res = maxDepth(&a)
	fmt.Println(res)

}