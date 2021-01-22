// main file

#include <iostream>
#include <array>
#define SIZE 5

typedef std::array<int, SIZE> tarr;

void quicksort(tarr& arr, size_t begin, size_t end);

int main(int argc, char **argv) {
	tarr myarr;
	std::cout << "Enter 5 elements for sorting: " << std::endl;
	for (int& num: myarr) {
		std::cin >> num;
	}
	quicksort(myarr, 0, SIZE - 1);
	std::cout << "array after sorting:\n\n" << std::endl;
	for (const int& num: myarr) {
		std::cout << num << "\t";
	}
	std::cout << std::endl;
	return 0;
}

void quicksort(tarr& arr, size_t begin, size_t end) {
	size_t pivot{}, i{}, j{};
	int temp{};
	if (begin < end) {
		pivot = begin;
		i = begin;
		j = end;

		while (i < j) {
			while (arr[i] <= arr[pivot] && i < end) { i++; }
			while (arr[j] > arr[pivot]) { j--; }
			if (i < j) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;
		quicksort(arr, begin, j - 1);
		quicksort(arr, j + 1, end);
	}
}