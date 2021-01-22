// main file

#include <iostream>
#include <array>
#define SIZE 20

bool linear_search(const std::array<int, SIZE>& arr, const size_t size, int key);
bool binary_search(const std::array<int, SIZE>& arr, size_t start, size_t end, const int key);

int main(int argc, char **argv) {
	size_t size;
	std::cout << "Enter the elements count to enter: " << std::endl;
	std::cin >> size;
	std::cout << "Enter elements of array[max count: 20]" << std::endl;
	std::array<int, SIZE> myarr;
	size_t i = 0;
	while (i < size) {
		std::cin >> myarr[i++];
	}
	int key;
	std::cout << "Enter element to search: " << std::endl;
	std::cin >> key;
	std::cout << (linear_search(myarr, size, key) ? "True" : "False") << "\n";
	std::cout << (binary_search(myarr, 0, SIZE - 1, key) ? "True" : "False") << std::endl;
	return 0;
}

bool linear_search(const std::array<int, SIZE>& arr, const size_t size, int key) {
	for (size_t i = 0; i < size; ++i) {
		if (arr[i] == key) {
			return true;
		}
	}
	return false;
}

bool binary_search(const std::array<int, SIZE>& arr, size_t start, size_t end, int key) {
	if (start <= end) {
		if (arr[start] == key) {
			return true;
		}
		else {
			size_t mid = (start + end) / 2;
			if (key == arr[mid]) { return true; }
			if (key < arr[mid]) {
				return binary_search(arr, 0, mid - 1, key);
			}
			else {
				return binary_search(arr, mid + 1, end, key);
			}
		}
	}
	return false;
}