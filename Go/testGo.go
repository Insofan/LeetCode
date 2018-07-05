package main

import (
	"fmt"
	"./problem206"
	"./Util"
)


func main() {
	a1 := util.ListNode{1, nil}
	a2 := util.ListNode{2, nil}
	a3 := util.ListNode{3, nil}
	a4 := util.ListNode{4, nil}
	a5 := util.ListNode{5, nil}
	a6 := util.ListNode{6, nil}

	a1.Next = &a2;
	a2.Next = &a3;
	a3.Next = &a4;
	a4.Next = &a5;
	a5.Next = &a6;
	head := problem206.ReverseList(&a1)
	for head != nil {
		fmt.Printf("%d ", head.Val)
		head = head.Next
	}
}

