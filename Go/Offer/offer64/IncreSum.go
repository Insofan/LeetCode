/**
 * Created with Goland.
 * Description: 
 * User: Insomnia
 * Date: 2019-01-21
 * Time: 下午11:50
 */

package offer64

func IncreSum(n int) int {

	sum := n

	if sum == 0{
		return sum
	} else {
		sum += IncreSum(n - 1)
	}
	return sum
}
