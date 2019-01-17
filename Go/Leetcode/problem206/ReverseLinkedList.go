package problem206

import (
	"../../Util"
)

func ReverseList(head *util.ListNode) *util.ListNode{
	var newHead *util.ListNode
	for head != nil {
		nextHead := head.Next
		head.Next = newHead

		newHead = head
		head = nextHead
	}

	return newHead
}
