/**
 * Created with Goland.
 * Description: 
 * User: Insomnia
 * Date: 2018-10-12
 * Time: 下午10:07
 */

package problem001

func twoSum(nums []int, target int) []int {
	hashMap := make(map[int]int)

	res := make([]int, 2)
	for i, val := range nums {
		hashMap[val] = i
	}
	for i, _ := range nums {
		other := target - nums[i]
		if j, ok:= hashMap[other]; ok== true {
			if j != i {
				res[0], res[1] = i, j
				return res
			}
		}
	}
	return res
}
