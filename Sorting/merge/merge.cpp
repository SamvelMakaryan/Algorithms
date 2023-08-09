#include <iostream>

template <typename T>
void merge(T* arr, int left, int mid, int right) {
	T* tmp = new T [right - left + 1];
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			tmp[k] = arr[i++];
		}
		else {
			tmp[k] = arr[j++];
		}
		++k;
	}
	while (i <= mid) {
		tmp[k++] = arr[i++];
	}
	while (j <= right) {
		tmp[k++] = arr[j++];
	}
	for (int i = 0; i < right - left + 1; ++i) {
		arr[i + left] = tmp[i];
	}
	delete[] tmp;
}

template <typename T>
void sort(T arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		sort(arr, left, mid);
		sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main() {
	int arr[] = {32, 45, 6, 7, -8, 7, 55, 2, 11, 20};
	sort(arr, 0, 9);
	for (auto& i: arr) {
		std::cout << i << "  ";
	}
}

// Time complexity O(n log n)
// Space complexity O(n)
