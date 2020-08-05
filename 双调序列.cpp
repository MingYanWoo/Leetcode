// 双调序列

// 给定一个序列，找出其中最长的双调序列，双调序列定义为一个先递减再递增的序列，或者先递增再递减的序列，
// //评测题目: 无

// [1,2,3,4,3,2,5,6,3]


#include <iostream>
#include <vector>

using namespace std;

int longest(vector<int> arr) {
	int n = arr.size();
	if(n == 1 || n == 0) return n;
	int first = 1, second = 0;
	int res = 0;
	bool up = arr[0] < arr[1] ? true : false;
	int i = 0;
	if(up) {
		while(arr[i+1] > arr[i]) {
			first++;
			i++;
		}
	}else {
		while(arr[i+1] < arr[i]) {
			first++;
			i++;
		}
	}
	up = !up;
	for(; i < n; i++) {
		second++;
		if(i == n - 1) {
			res = max(res, first + second - 1);
			continue;
		}
		if((up && arr[i-1] < arr[i] && arr[i] > arr[i+1]) || 
			(!up && arr[i-1] > arr[i] && arr[i] < arr[i+1])) {
			up = !up;
			res = max(res, first + second - 1);
			first = second;
			second = 1;
		}		
	}
	return res;
}

int main() {
	int n[] = {1,2,3,4,3,2,5,6,3};
	vector<int> a(n, n+9);
	cout << longest(a) << endl;
	return 0;
}