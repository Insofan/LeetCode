//
//  LCA.go
//  Go 
//
//  Created by Inso on 2019/1/21.
//  Copyright © 2019 Inso. All rights reserved.
//
package offer68

import "LeetCode/Go/Util"

func LowestCommonAncestorNode(root, fir, sec *util.TreeNode) *util.TreeNode {
	if root == nil || root == fir || root == sec {
		return root
	}

	p1 := LowestCommonAncestorNode(root.Left, fir, sec)
	p2 := LowestCommonAncestorNode(root.Right, fir, sec)
	if p1 != nil && p2 != nil {
		return root
	}

	if p1 != nil {
		return p1
	} else {
		return p2
	}
}
