//
//  WhileQuickSort.go
//  Go 
//
//  Created by Inso on 2019/1/17.
//  Copyright © 2019 Inso. All rights reserved.
//
package WhileQuickSort

func WhileQuickSort(arr []int, left, right int) {
	l := left
	r := right
	pivot := arr[l]
	for l < r {
		for (l < r) && (arr[r] >= pivot) {
			r--
		}
		if l < r {
			arr[l], arr[r] = arr[r], arr[l]
		}
		for (l < r) && (arr[l] <= pivot) {
			l++
		}
		if l < r {
			arr[l], arr[r] = arr[r], arr[l]
		}
	}
	if l != left {
		WhileQuickSort(arr, left, l-1)
	}
	if r != right {
		WhileQuickSort(arr, r+1, right)
	}
}

