# 面试题 08.10. Color Fill LCCI
# Implement the "paint fill" function that one might see on many image editing programs. That is, given a screen (represented by a two-dimensional array of colors), a point, and a new color, fill in the surrounding area until the color changes from the original color.

# Example1:

# Input: 
# image = [[1,1,1],[1,1,0],[1,0,1]] 
# sr = 1, sc = 1, newColor = 2
# Output: [[2,2,2],[2,2,0],[2,0,1]]
# Explanation: 
# From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
# by a path of the same color as the starting pixel are colored with the new color.
# Note the bottom corner is not colored 2, because it is not 4-directionally connected
# to the starting pixel.
# Note:

# The length of image and image[0] will be in the range [1, 50].
# The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
# The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        if image[sr][sc] == newColor:
            return image

        m = len(image)
        n = len(image[0])
    
        def dfs(x, y, r, c):
            if image[x][y] != r:
                return
            
            image[x][y] = c
            for dx,dy in [(0,1),(1,0),(0,-1),(-1,0)]:
                new_x = x + dx
                new_y = y + dy
                if 0 <= new_x < m and 0 <= new_y < n:
                    dfs(new_x, new_y, r, c)
        
        dfs(sr, sc, image[sr][sc], newColor)
        return image