//
//  LCA_test.go
//  Go 
//
//  Created by Inso on 2019/1/21.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer68

import (
	"testing"
	"LeetCode/Go/Util"
	"fmt"
)

func TestLowestCommonAncestorNode(t *testing.T) {
	arr := []int{0, 1, 2, 3, 4, 5, 6}
	root := util.Arr2TreeNode(arr)

	fmt.Println(root.Left.Val)

	p := util.GetTarNode(root, 3)
	q := util.GetTarNode(root, arr[4])

	ans := LowestCommonAncestorNode(root, p, q)
	fmt.Printf("Lowest Common Ancestor Node p: %d q: %d lca: %d\n", p.Val, q.Val, ans.Val)

	if ans != util.GetTarNode(root, arr[1]) {
		t.Error("LCA err")
	}
}