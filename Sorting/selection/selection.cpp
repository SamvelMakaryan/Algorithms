#include <iostream>

template <typename T>
void sort(T arr, int n) {
	for (int j = 0; j < n - 1; ++j) {
		int min = j;
		for (int i = j + 1; i < n; ++i) {
			if (arr[min] > arr[i]) {
				min = i;
			}
		}
		std::swap(arr[min], arr[j]);
	}
}
int main() {
	int arr[] = {12, -4, 5, 0, 7, 8, -3, 17, 4, -4};
	sort(arr, 10);
	for (auto& i : arr) {
		std::cout << i << "  ";
	}
}

// Time complexity O(n^2)
// Space complexity O(1)
