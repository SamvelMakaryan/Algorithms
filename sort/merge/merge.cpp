#include <iostream>

template <typename T>
void merge(T* arr, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	T* arr1 = new T [n1];
	T* arr2 = new T [n2];
	for (int i = 0; i < n1; ++i) {
		arr1[i] = arr[left + i];
	}
	for (int i = 0; i < n2; ++i) {
		arr2[i] = arr[mid + 1 + i];
	}
	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2) {
		if (arr1[i] >= arr2[j]) {
			arr[k] = arr2[j++];
		}
		else {
			arr[k] = arr1[i++];
		}
		++k;
	}
	while (i < n1) {
		arr[k++] = arr1[i++];
	}
	while(j < n2) {
		arr[k++] = arr2[j++];
	}
	delete[] arr1;
	delete[] arr2;
}

template <typename T>
void sort(T arr, int left, int right) {
	if (left >= right) {
		return;
	}
	int mid = left + (right - left) / 2;
	sort(arr, left, mid);
	sort(arr, mid + 1, right);
	merge(arr, left, mid, right);
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
