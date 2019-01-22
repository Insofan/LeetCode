/**
 * Created with Goland.
 * Description: 
 * User: Insomnia
 * Date: 2019-01-22
 * Time: 下午10:43
 */

package offer59_02


type MonnotonicQue struct {
	que []int
}

func Constructor() MonnotonicQue {
	return MonnotonicQue{}
}

func (mq *MonnotonicQue) Push(x int) {
	for len(mq.que) > 0 && x > mq.que[len(mq.que)-1] {
		mq.que = mq.que[0 : len(mq.que)-1]
	}
	mq.que= append(mq.que, x)
}

func (mq *MonnotonicQue) Pop()  {
	mq.que = mq.que[1:len(mq.que)]
}

func (mq *MonnotonicQue) Max()  int {
	return mq.que[0]
}

func SlideMaxWindow(arr []int, width int) []int {
	mq := MonnotonicQue{}

	res := []int{}
	for i, val := range arr {
		mq.Push(val)
		if (i - width+1 ) >= 0 {
			res = append(res, mq.Max())
		}

		if  i - width+1 >= 0 && arr[i - width + 1] == mq.Max() {
			mq.Pop()
		}
	}
	return res
}