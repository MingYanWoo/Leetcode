maps = [
'S###.',
'...#.',
'E#.##',
'.#..#',
'.####'
]
maps = list([list(s) for s in maps])

# print(maps)

dice = [1, 6, 5, 2, 3, 4] #up, bottom, left, right, front, back

def change(i):
	if i == 1: # right
		templ = dice[1]
		tempr = dice[0]
		dice[0] = dice[2]
		dice[1] = dice[3]
		dice[2] = templ
		dice[3] = tempr
	elif i == 2: # left
		templ = dice[0]
		tempr = dice[1]
		dice[0] = dice[3]
		dice[1] = dice[2]
		dice[2] = templ
		dice[3] = tempr
	elif i == 3: # up
		tempu = dice[4]
		tempb = dice[5]
		dice[4] = dice[1]
		dice[5] = dice[0]
		dice[0] = tempu
		dice[1] = tempb
	else: # bottom
		tempu = dice[5]
		tempb = dice[4]
		dice[4] = dice[0]
		dice[5] = dice[1]
		dice[0] = tempu
		dice[1] = tempb

def dfs(x, y):
	if maps[x][y] == 'E':
		maps[x][y] = dice[1]
		return
	maps[x][y] = dice[1]
	moves = [(0,1),(0,-1),(-1,0),(1,0)]
	for i, (dx,dy) in enumerate(moves):
		new_x = x + dx
		new_y = y + dy
		if 0 <= new_x < len(maps) and 0 <= new_y < len(maps[0]):
			if maps[new_x][new_y] == '#' or maps[new_x][new_y] == 'E':
				change(i+1)
				dfs(new_x, new_y)

def main():
	start = (0, 0)
	for i in range(len(maps)):
		for j in range(len(maps[0])):
			if maps[i][j] == 'S':
				start = (i, j)
				break

	dfs(start[0], start[1])

	print(maps)


if __name__ == '__main__':
	main()