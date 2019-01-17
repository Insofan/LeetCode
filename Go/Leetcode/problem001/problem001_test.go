/**
 * Created with Goland.
 * Description: 
 * User: Insomnia
 * Date: 2018-10-12
 * Time: 下午10:08
 */

package problem001

import "testing"

func TestTwoSum(t *testing.T) {
	input := []int{2, 7, 11, 15}
	want := []int{0, 1}

	res := twoSum(input, 9)
	for i, val := range res {
		if val != want[i] {
			t.Error("two sum failed")
		}
	}
}
