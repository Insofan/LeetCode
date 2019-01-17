package problem206

import (
	"testing"
	"../../Util"
	"fmt"
)

type question struct {
	para
	ans
}

// para 是参数
// one 代表第一个参数
type para struct {
	one []int
}

// ans 是答案
// one 代表第一个答案
type ans struct {
	one []int
}

func TestReverseList(t *testing.T) {
	qs := []question{

		question{
			para{[]int{1, 2, 3, 4, 5}},
			ans{[]int{5, 4, 3, 2, 1}},
		},
		question{
			para{[]int{5, 6, 7, 8, 9}},
			ans{[]int{9, 8, 7, 6, 5}},
		},

		// 如需多个测试，可以复制上方元素。
	}

	for _, q := range qs {
		a, p := q.ans, q.para
		fmt.Println("输出:", p.one)
		ans := l2s(ReverseList(s2l(p.one)))
		fmt.Println("预期:",a.one)
		fmt.Println("输出:", ans)
	}
}

// convert *ListNode to []int
func l2s(head *util.ListNode) []int {
	res := []int{}

	for head != nil {
		res = append(res, head.Val)
		head = head.Next
	}

	return res
}

// convert []int to *ListNode
func s2l(nums []int) *util.ListNode {
	if len(nums) == 0 {
		return nil
	}

	res := &util.ListNode{
		Val: nums[0],
	}
	temp := res
	for i := 1; i < len(nums); i++ {
		temp.Next = &util.ListNode{
			Val: nums[i],
		}
		temp = temp.Next
	}

	return res
}
