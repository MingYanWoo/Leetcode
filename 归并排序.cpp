// 归并排序
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int start, int mid, int end) {
	vector<int> temp(end-start+1, 0);
	int i = start, j = mid+1, k = 0;
	while(i <= mid && j <= end) {
		if(arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}else {
			temp[k++] = arr[j++];
		}
	}
	while(i <= mid) {
		temp[k++] = arr[i++];
	}
	while(j <= end) {
		temp[k++] = arr[j++];
	}
	for(i = start, k = 0; i <= end; i++, k++) {
		arr[i] = temp[k];
	}
}

void mergeSort(vector<int>& arr, int start, int end) {
	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

int main() {
	int a[7] = {3,5,2,53,6,3,1};
	vector<int> list(a, a+7);
	mergeSort(list, 0, list.size()-1);
	for(int i = 0; i < list.size(); i++) {
		cout << list[i] << ' ';
	}
	cout << endl;
	return 0;
}