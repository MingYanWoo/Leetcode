# select sort

def select_sort(arr):
	n = len(arr)
	for i in range(n-1):
		minVal = arr[i]
		minIdx = i
		for j in range(minIdx+1, n):
			if arr[j] < minVal:
				minVal = arr[j]
				minIdx = j
		arr[i], arr[minIdx] = arr[minIdx], arr[i]
	return arr

if __name__ == '__main__':
	arr = [1,3,4,2,8,5,6,2,3,4]
	print(select_sort(arr))