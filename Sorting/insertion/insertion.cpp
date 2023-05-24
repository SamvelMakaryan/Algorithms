#include <iostream>

template <typename T>
void sort(T arr, int n) {
	for (int i = 1; i < n; ++i) {
		int j = i - 1;
		int key = arr[i];
		while(j >= 0 && arr[j] > key) {
			arr[j-- + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}

int main() {
	int arr[] = {5, 1, -4, 2, 19, -8, 7, 31, 2, 6};
	sort(arr, 10);
	for (auto& i : arr) {
		std::cout << i << "  ";
	}
}

// Time complexity O(n^2)
// Space complexity O(1)
