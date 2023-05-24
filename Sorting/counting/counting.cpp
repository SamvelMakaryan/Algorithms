#include <iostream>
#include <algorithm>

template <typename T>
void sort(T* arr, int n) {
    int max = *std::max_element(arr, arr + n);
	int min = *std::min_element(arr, arr + n);
    int* count = new int[max - min + 1]{};
    for (int i = 0; i < n; ++i) {
        count[arr[i] - min]++;
    }
	for (int i = 1; i <= max - min + 1; ++i) {
        count[i] += count[i - 1];
    }
    T* tmp = new T[n];
    for (int i = n - 1; i >= 0; --i) {
        tmp[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = tmp[i];
    }
    delete[] count;
    delete[] tmp;
}

int main() {
    int arr[] = {32, 45, 6, 7, -8, 7, 55, 2, 11, 20};
   	sort(arr, 10);
    for (auto& i : arr) {
        std::cout << i << " ";
    }
    return 0;
}


//Time complexity O(n + k)
//Space complexity O(n + k)
//where k is range of elements
