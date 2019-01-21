/**
 * Created with Goland.
 * Description: 
 * User: Insomnia
 * Date: 2019-01-22
 * Time: 上午12:05
 */

package offer64

import (
	"fmt"
	"testing"
)

func TestIncreSum(t *testing.T) {
	res := IncreSum(100)
	want := 5050

	fmt.Println("1+2+...n sum is : ",res)
	fmt.Println()
	if want != res {
		t.Error("不用if else switch等条件操作和求和公式 答案错误")
	}
}
