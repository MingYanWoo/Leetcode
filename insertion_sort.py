# insertion sort

def insertion_sort(arr):
	n = len(arr)
	for i in range(1, n):
		temp = arr[i]
		j = i - 1
		while j >= 0 and arr[j] > temp:
			arr[j+1] = arr[j]
			j -= 1
		arr[j+1] = temp
	return arr

if __name__ == '__main__':
	arr = [1,3,4,2,5,6,2,3,4]
	print(insertion_sort(arr))