/**
 * Created with Goland.
 * Description: 
 * User: Insomnia
 * Date: 2019-01-21
 * Time: 下午10:51
 */

package util

import (
	"fmt"
	"testing"
)

func TestLevelOrder(t *testing.T) {
	arr := []int{1, 2, 3, 4, 5, 6, 7}
	root := Arr2TreeNode(arr)
	res := LevelOrder(root)
	want := [][]int{{1}, {2, 3}, {4, 5, 6, 7} }

	if len(res) == 0 {
		t.Error("Level order err")
	}
	for index,value := range res {
		fmt.Print(index," level :")
		for i,_ := range value {
			fmt.Print(want[index][i], " ")
			if want[index][i] != res[index][i] {
				t.Error("Level order err")
			}
		}
		fmt.Println()
	}

}
