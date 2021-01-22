// main file

#include <iostream>
#include <array>
#define SIZE 5

void part(std::array<int, SIZE>& arr, size_t min, size_t max);
void merge(std::array<int, SIZE>& arr, size_t min, size_t mid, size_t max);

int main(int argc, char **argv) {
	std::array<int, SIZE> myarr;
	std::cout << "Enter the numbers in array: " << std::endl;
	for (size_t i = 0; i < SIZE; ++i) {
		std::cin >> myarr[i];
	}
	part(myarr, 0, SIZE - 1);
	for (int num: myarr) {
		std::cout << num << "\t";
	}
	std::cout << std::endl;
	return 0;
}

void part(std::array<int, SIZE>& arr, size_t min, size_t max) {
	size_t mid;
	if (min < max) {
		mid = (min + max) / 2;
		part(arr, min, mid);
		part(arr, mid + 1, max);
		merge(arr, min, mid, max);
	}
}

void merge(std::array<int, SIZE>& arr, size_t min, size_t mid, size_t max) {
	std::array<int, SIZE> tmp_arr;
	size_t i{}, j = min, k{}, m = mid + 1;
	for (i = min; j <= mid && m <= max; ++i) {
		if (arr[j] <= arr[m]) {
			tmp_arr[i] = arr[j++];
		}
		else {
			tmp_arr[i] = arr[m++];
		}
	}
	if (j > mid) {
		for (k = m; k <= max; ++k) {
			tmp_arr[i++] = arr[k];
		}
	}
	else {
		for (k = j; k <= mid; ++k) {
			tmp_arr[i++] = arr[k];
		}
	}
	for (k = min; k <= max; ++k) {
		arr[k] = tmp_arr[k];
	}
}