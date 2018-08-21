//
//  LowestCommonAncestorOfABinaryTree.go
//  Go 
//
//  Created by Inso on 2018/8/20.
//  Copyright © 2018 Inso. All rights reserved.
//
package main

import (
	"../Util"
	"fmt"
)

func lowestCommonAncestor(root, p, q *util.TreeNode) *util.TreeNode {
	var res *util.TreeNode
	var path []*util.TreeNode
	var pPath []*util.TreeNode
	var qPath []*util.TreeNode
	finish := 0
	fmt.Printf("%p \n", &pPath)
	generate(root, p, &finish, &path, &pPath)
	finish = 0
	path = nil
	generate(root, q, &finish, &path, &qPath)
	pathLen := minNum(len(qPath), len(pPath))

	for i := 0; i < pathLen; i++ {
		if (pPath[i] == qPath[i]) {
			res = pPath[i]
		}
	}

	return res
}

func minNum(x, y int) int {
	if (x < y) {
		return x
	} else {
		return y
	}
}

func generate(root *util.TreeNode, search *util.TreeNode, finish *int, path *[]*util.TreeNode, res *[]*util.TreeNode) {
	if (root == nil || *finish == 1) {
		return
	}

	fmt.Printf("%p", res)
	*path = append(*path, root)

	if (root == search) {
		*finish = 1
		res = path
		fmt.Println(len(*res))
	}

	generate(root.Left, search, finish, path, res)
	generate(root.Right, search,finish, path, res)
	path = path[:len(*path) - 1]

}

func main() {
	a := util.TreeNode{3, nil, nil}
	b := util.TreeNode{5, nil, nil}
	c := util.TreeNode{6, nil, nil}
	d := util.TreeNode{2, nil, nil}
	e := util.TreeNode{7, nil, nil}
	f := util.TreeNode{4, nil, nil}
	g := util.TreeNode{1, nil, nil}
	h := util.TreeNode{0, nil, nil}
	i := util.TreeNode{8, nil, nil}

	a.Left = &b
	b.Left = &c
	b.Right = &d
	d.Left = &e
	d.Right = &f
	a.Right = &g
	g.Left = &h
	g.Right = &i

	fmt.Println(lowestCommonAncestor(&a, &b, &g))
}
