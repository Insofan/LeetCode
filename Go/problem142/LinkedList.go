/**
 * Created with Goland.
 * Description: 
 * User: Insomnia
 * Date: 2018-09-03
 * Time: 下午11:16
 */

package main

import (
	"../Util"
	"fmt"
)

func findLinedNode(node *util.ListNode) *util.ListNode  {
	slow := node
	fast := node
	var meet *util.ListNode = nil

	for fast != nil {
		slow = slow.Next
		fast = fast.Next
		if fast == nil {
			return nil
		}
		fast = fast.Next
		if (slow == fast) {
			meet = fast
			break
		}
	}

	if (meet == nil) {
		return nil
	}

	for meet != nil && node != nil {
		if (meet == node) {
			return meet
		}
		meet = meet.Next
		node = node.Next
	}

	return nil
}

func main()  {

	a1 := util.ListNode{1, nil}
	a2 := util.ListNode{2, nil}
	a3 := util.ListNode{3, nil}
	a4 := util.ListNode{4, nil}
	a5 := util.ListNode{5, nil}
	a6 := util.ListNode{6, nil}
	a7 := util.ListNode{7, nil}

	a1.Next = &a2
	a2.Next = &a3
	a3.Next = &a4
	a4.Next = &a5
	a5.Next = &a6
	a6.Next = &a7
	a7.Next = &a3
	res := findLinedNode(&a1)
	if res == nil {
		fmt.Println(-1)
	} else {
		fmt.Println(res.Val)
	}
}
