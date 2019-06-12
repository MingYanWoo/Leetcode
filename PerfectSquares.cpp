// 279. Perfect Squares

// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

// Example 1:

// Input: n = 12
// Output: 3 
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.

class Solution {
public:
    int numSquares(int n) {
        while(n % 4 == 0) n /= 4;
        if(n % 8 == 7) return 4;
        for(int a = 0; a * a <= n; a++) {
            int b = sqrt(n - a * a);
            if(a*a + b*b == n) {
                return !!a + !!b;
            }
        }
        return 3;
    }
};