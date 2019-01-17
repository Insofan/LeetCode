//
//  SameTree.go
//  Go 
//
//  Created by Inso on 2018/8/20.
//  Copyright © 2018 Inso. All rights reserved.
//
package main

import (
	"../../Util"
	"fmt"
)

func isSameTree(a, b *util.TreeNode) bool {
	if (a == nil || b == nil) {
		return a == b
	}	else {
		return a.Val == b.Val && isSameTree(a.Left, b.Left) && isSameTree(a.Right, b.Right)
	}
}

func main() {
	a1 := util.TreeNode{1, nil, nil}
	b1 := util.TreeNode{2, nil, nil}
	c1 := util.TreeNode{3, nil, nil}

	a2 := util.TreeNode{1, nil, nil}
	b2 := util.TreeNode{2, nil, nil}
	c2 := util.TreeNode{3, nil, nil}

	a1.Left = &b1
	a1.Right = &c1

	a2.Left = &b2
	a2.Right = &c2

	res := isSameTree(&a1, &a2)
	fmt.Println(res)
}
