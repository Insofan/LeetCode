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
	"../Util"
)

func maxDepth(root *util.TreeNode) int {

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

}