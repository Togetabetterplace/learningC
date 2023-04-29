#include<iostream>
using namespace std;
void qu(int *a, int l, int r) {
	if (l < r) {
		int k = l;
		int i = l, j = r;
		while (i < j) {
			while (a[i] <= a[k] && i < r)i++;
			while (a[j] >= a[k] && j > l)j--;
			if (i < j) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
		int e = a[k];
		a[k] = a[j];
		a[j] = e;
		qu(a, l, j - 1);//递归调用
		qu(a, j + 1, r);
	}
}
int pat(int nums[], int low, int high) {
	int piv = nums[low];
	while (low < high) {
		while (low < high && nums[high] >= piv) {
			--high;
		}//在右边找比pivot小的，复制过来
		nums[low] = nums[high];
		while (low < high && nums[low] <= piv) {
			++low;
		}//在左边找比pivot大的，复制过来
		nums[high] = nums[low];
	}
	nums[low] = piv;
	return low;
}
int Top_k(int nums[], int k, int low, int high) {
	if (low < high) {
		int pivot = pat(nums, low, high);
		while (pivot != k - 1) {
			if (pivot < k - 1) {
				pivot = pat(nums, pivot + 1, high);
			} else {
				pivot = pat(nums, low, pivot - 1);
			}
		}
		return pivot;
	}
}
int main() {
	int n = 0, k = 0, num[100];
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	cout << Top_k(num, k + 1, 1, n) << endl;
}
