/**
 * Created with Goland.
 * Description: 
 * User: Insomnia
 * Date: 2019-01-22
 * Time: 下午10:33
 */

package offer59_01

import (
	"fmt"
	"testing"
)

func TestMaxQue(t *testing.T) {

	mq := MaxQue{}
	mq.Push(1)
	mq.Push(2)
	mq.Push(0)
	mq.Push(10)
	mq.Push(3)
	mq.Push(2)
	res := mq.Max()
	fmt.Println("最大值为: ", res)
	want := 10
	if res != want {
		t.Error("Offer 59: 最大队列值错误")
	}
}
