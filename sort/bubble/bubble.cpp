#include <iostream>

template <typename T>
void sort(T arr, int n) {
	bool is_finished = true;
	int i = 0;
	while (is_finished) {
		is_finished = false;
		for (int i = 0; i < n - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				is_finished = true;
			}
		}
	}
}

int main() {
	int arr[] = {6, 3, 7, -9, 0, 12, 14, 7, 88, -11};
	sort(arr, 10);
	for (auto& i : arr) {
		std::cout << i << "  ";
	}
}

// Time complexity O(n^2)
// Space complexity O(1)
