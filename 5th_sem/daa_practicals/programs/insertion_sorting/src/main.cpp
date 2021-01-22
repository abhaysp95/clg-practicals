// main file

#include <iostream>
#include <array>
#define SIZE 5

typedef std::array<int, SIZE> tarr;

void insertion_sort(tarr& arr);

int main(int argc, char **argv) {
	tarr myarr;
	std::cout << "Enter 5 elements:" << std::endl;
	for (int& num: myarr) {
		std::cin >> num;
	}
	insertion_sort(myarr);
	std::cout << "array after sorting: \n\n";
	for (const int& num: myarr) {
		std::cout << num << "\t";
	}
	std::cout << std::endl;
	return 0;
}

void insertion_sort(tarr& arr) {
	for (size_t c = 1; c <= SIZE - 1; ++c) {
		size_t d = c;
		while (d > 0 && arr[d] < arr[d - 1]) {
			int temp = arr[d];
			arr[d] = arr[d - 1];
			arr[d - 1] = temp;
			d--;
		}
	}
}