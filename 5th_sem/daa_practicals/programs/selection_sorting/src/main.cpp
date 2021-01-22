// main file

#include <iostream>
#include <array>
#define SIZE 10

void selection_sort(std::array<int, SIZE>& arr);

int main(int argc, char **argv) {
	std::array<int, SIZE> myarr;
	std::cout << "Enter 10 integers in array: " << std::endl;
	for (int& num: myarr) {
		std::cin >> num;
	}
	std::cout << "Array after sorting\n\n";
	selection_sort(myarr);
	for (const int& num: myarr) {
		std::cout << num << "\t";
	}
	std::cout << std::endl;
	return 0;
}

void selection_sort(std::array<int, SIZE>& arr) {
	size_t pos{};
	int swap{};
	for (size_t c = 0; c < (SIZE - 1); ++c) {
		pos = c;
		for (size_t d = c + 1; d < SIZE; ++d) {
			if (arr[pos] > arr[d]) {
				pos = d;
			}
		}
		if (pos != c) {
			swap = arr[c];
			arr[c] = arr[pos];
			arr[pos] = swap;
		}
	}
}