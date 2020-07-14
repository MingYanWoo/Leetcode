# quick sort

def qsort(arr, low, high):
	if low < high:
		mid = partition(arr, low, high)
		qsort(arr, low, mid-1)
		qsort(arr, mid+1, high)

def partition(arr, start, end):
	last = arr[end]
	while start < end:
		while start < end and arr[start] <= last:
			start += 1
		arr[end] = arr[start]
		while start < end and arr[end] > last:
			end -= 1
		arr[start] = arr[end]
	arr[start] = last
	return start

if __name__ == '__main__':
	arr = [1,5,3,4,8,7,5,32,1,3,5,32,3,6,8]
	qsort(arr, 0, len(arr)-1)
	print(arr)