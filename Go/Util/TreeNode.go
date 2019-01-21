//
//  TreeNode.go
//  Go 
//
//  Created by Inso on 2018/8/20.
//  Copyright © 2018 Inso. All rights reserved.
//
package util

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

// NULL 方便添加测试数据
var NULL = -1 << 63

func Arr2TreeNode(arr []int) *TreeNode {
	n := len(arr)
	if n == 0 {
		return nil
	}
	root := &TreeNode{
		arr[0],
		nil,
		nil,
	}

	queue := make([]*TreeNode, 1, n*2)
	queue[0] = root

	i := 1
	for i < n {
		node := queue[0]
		queue = queue[1:]

		if  i < n && arr[i] != NULL {
			node.Left = &TreeNode{
				arr[i],
				nil,
				nil,
			}
			queue = append(queue, node.Left)
		}
		i++

		if i < n && arr[i] != NULL {
			node.Right = &TreeNode{
				arr[i],
				nil,
				nil,
			}
			queue = append(queue, node.Right)
		}
		i++
	}
	return root
}

func GetTarNode(root *TreeNode, tar int) *TreeNode {
	if root == nil || root.Val == tar {
		return root
	}

	res := GetTarNode(root.Left, tar)
	if res != nil {
		return res
	}

	return GetTarNode(root.Right, tar)
}



