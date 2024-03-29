#include <iostream>

template <typename T>
void sort(T* arr, int left, int right) {
	if (left < right) {
		int i = left;
		int j = right;
		T pivot = arr[left + (right - left) / 2];
		while (i <= j) {
			while (arr[i] < pivot) {
				++i;
			}
			while (arr[j] > pivot) {
				--j;
			}
			if (i <= j) {
				std::swap(arr[i++], arr[j--]);
			}
		}
		sort(arr, left, j);
		sort(arr, i, right);
	}
}

int main() {
	int arr[] = {3, -5, 67, 89, 22, 0, 22, 343, -7, -109};
	sort(arr, 0, 9);
	for (auto& i: arr) {
		std::cout << i << "  ";
	}
}

// Time complxity O(n^2)
// Space complexity O(n)
