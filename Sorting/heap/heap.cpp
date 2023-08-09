#include <iostream>

template <typename T>
void heapify(T arr, int n, int i) {
	int root = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && arr[left] > arr[root]) {
		root = left;
	}
	if (right < n && arr[right] > arr[root]) {
		root = right;
	}
	if (root != i) {
		std::swap(arr[i], arr[root]);
		heapify(arr, n, root);
	}
}

template <typename T>
void sort(T arr, int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; --i) {
        std::swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {5, 1, -4, 2, 19, -8, 7, 31, 2, 6};
	sort(arr, 10);
	for (auto& i : arr) {
		std::cout << i << "  ";
	}
}
//Time complexity O(n logn)
//Space complexity O(1)
