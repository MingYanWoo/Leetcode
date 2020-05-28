// 378. 有序矩阵中第K小的元素
// 给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
// 请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。

 

// 示例:

// matrix = [
//    [ 1,  5,  9],
//    [10, 11, 13],
//    [12, 13, 15]
// ],
// k = 8,

// 返回 13。
 

// 提示：
// 你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。



class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];
        while(l < r) {
            int mid = (l + r) / 2;
            if(count(matrix, mid) < k) {
                l = mid + 1;
            }else {
                r = mid;
            }
        }
        return l;
    }

    int count(vector<vector<int>>& matrix, int num) {
        int i = matrix.size() - 1, j = 0;
        int ans = 0;
        while(i >= 0 && j < matrix[0].size()) {
            if(matrix[i][j] > num) {
                i--;
            }else {
                ans += i + 1;
                j++;
            }
        }
        return ans;
    }

};