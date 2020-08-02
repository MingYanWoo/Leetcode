# 拼多多-骰子种类

def roll(arr, direction):
	# 0-前 1-后 2-左 3-右
	if direction == 0:
		tempup = arr[0]
		tempdown = arr[1]
		arr[0] = arr[5]
		arr[1] = arr[4]
		arr[4] = tempup
		arr[5] = tempdown
	elif direction == 1:
		tempup = arr[0]
		tempdown = arr[1]
		arr[0] = arr[4]
		arr[1] = arr[5]
		arr[4] = tempdown
		arr[5] = tempup
	elif direction == 2:
		tempup = arr[0]
		tempdown = arr[1]
		arr[0] = arr[3]
		arr[1] = arr[2]
		arr[2] = tempup
		arr[3] = tempdown
	else:
		tempup = arr[0]
		tempdown = arr[1]
		arr[0] = arr[2]
		arr[1] = arr[3]
		arr[2] = tempdown
		arr[3] = tempup
	return arr


def isSame(arr1, arr2):
	arr2 = reset(arr2)

	assert arr2[0] != 1

	for _ in range(4):
		if arr1 == arr2:
			return True
		arr2 = roll(arr2, 3)
	return False


def reset(arr2):
	if arr2[0] == 1:
		arr2 = roll(arr2, 0)
	elif arr2[2] == 1:
		arr2 = roll(arr2, 3)
		arr2 = roll(arr2, 0)
	elif arr2[3] == 1:
		arr2 = roll(arr2, 2)
		arr2 = roll(arr2, 0)
	elif arr2[1] == 1:
		arr2 = roll(arr2, 1)
	elif arr2[5] == 1:
		arr2 = roll(arr2, 0)
		arr2 = roll(arr2, 0)
	return arr2


if __name__ == '__main__':
	# 2
	# 1 2 3 4 5 6
	# 1 2 6 5 3 4
	n = input()
	alist = []
	# n = 2
	# alist = [[1,2,3,4,5,6], [1,2,6,5,3,4]]
	# n = 3
	# alist = [[1,2,3,4,5,6],[1,2,6,5,3,4],[1,2,3,4,6,5]]
	for i in range(n):
		a = list(map(int, input().split(' ')))
		a = reset(a)
		alist.append(a)
		# alist[i] = reset(alist[i])

	record = []
	record.append([alist[0], 1])
	for i in range(1, len(alist)):
		arr2 = alist[i]
		inList = False
		for j in range(len(record)):
			arr1, cnt = record[j]	
			if isSame(arr1, arr2):
				inList = True
				record[j][1] += 1
				break
		if not inList:
			record.append([arr2, 1])

	print(len(record))
	record = sorted(record, key=lambda y: y[1], reverse=True)
	for i in range(len(record)):
		if i == len(record) - 1:
			print(record[i][1])
		else:
			print(str(record[i][1])+' ', end='')










