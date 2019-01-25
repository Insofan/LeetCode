//
//  CountSmallerOfSelf.go
//  Go
//
//  Created by Inso on 2019/1/25.
//  Copyright © 2019 Inso. All rights reserved.
//

// Package offer51 逆序对
package offer51

// CountSmallerOfSelf  逆序对

// BSTree 二叉搜索树
type BSTree struct {
	val   int
	count int
	left  *BSTree
	right *BSTree
}

func (bst *BSTree) insert(root, node *BSTree, small *int) {
	if node.val <= root.val {
		root.count++
		if root.left != nil {
			bst.insert(root.left, node, small)
		} else {
			root.left = node
		}
	} else {
		*small += root.count + 1

		if root.right != nil {
			bst.insert(root.right, node, small)
		} else {
			root.right = node
		}
	}
}

// CountSmallerOfSelf 逆序对
func CountSmallerOfSelf(arr []int) []int {
	res := []int{}

	var tmp []*BSTree

	for i := len(arr) - 1; i >= 0; i-- {
		tmp = append(tmp, &BSTree{arr[i], 0, nil, nil})
	}

	res = append(res, 0)

	bst := BSTree{}
	for i := 1; i < len(tmp); i++ {
		small := 0
		bst.insert(tmp[0], tmp[i], &small)
		res = append(res, small)
	}

	for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
		res[i], res[j] = res[j], res[i]
	}

	return res
}
