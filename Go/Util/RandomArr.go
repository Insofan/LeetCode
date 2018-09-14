/**
 * Created with Goland.
 * Description:
 * User: Insomnia
 * Date: 2018-09-14
 * Time: 下午8:40
 */

package util

import (
	"math/rand"
	"time"
)

func RandomArr(len, maxNum int) []int {
	rand.Seed(time.Now().Unix())
	var res []int
	for i := 0; i < len; i++ {
		x := rand.Intn(maxNum)
		res = append(res, x)
	}
	return res
}
