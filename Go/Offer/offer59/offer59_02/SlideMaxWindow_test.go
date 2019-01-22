/**
 * Created with Goland.
 * Description: 
 * User: Insomnia
 * Date: 2019-01-22
 * Time: 下午11:00
 */

package offer59_02

import (
	"fmt"
	"testing"
)

func TestSlideMaxWindow(t *testing.T) {
	arr := []int{1, 3, -1, -3, 5, 3, 6, 7}
	res := SlideMaxWindow(arr, 3)

	fmt.Println(res)
}
