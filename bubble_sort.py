def bubble_sort(arr):
	n = len(arr)
	for i in range(n):
		for j in range(n-i-1):
			if arr[j+1] < arr[j]:
				arr[j+1], arr[j] = arr[j], arr[j+1]
		print(arr)
	return arr

if __name__ == '__main__':
	arr = [1,3,4,2,5,6,2,3,4]
	print(bubble_sort(arr))