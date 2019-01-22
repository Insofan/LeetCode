/**
 * Created with Goland.
 * Description: 
 * User: Insomnia
 * Date: 2019-01-22
 * Time: 下午10:15
 */

package offer59_01

type MaxQue struct {
	que []int
}

func Constructor() MaxQue {
	return MaxQue{}
}

func (q *MaxQue) Push(x int) {
	for len(q.que) > 0 && x > q.que[len(q.que)-1] {
		q.que = q.que[:len(q.que)-1]
	}
	q.que = append(q.que, x)
}

func (q *MaxQue) Pop(x int) {
	q.que = q.que[1:len(q.que)]
}

func (q *MaxQue) Max() int {
	return q.que[0]
}