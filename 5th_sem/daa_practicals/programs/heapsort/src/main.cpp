// main file

#include <iostream>
#include <array>
#define SIZE 5

void manage(std::array<int, SIZE>& arr, int i);
void heapsort(std::array<int, SIZE>& arr, int i, size_t size);

int main(int argc, char **argv) {
	std::array<int, SIZE> myarr;
	std::cout << "\n--- Heap Sorting ---\n\n";
	std::cout << "Enter the elements in array to sort: " << std::endl;
	for (size_t i = 0; i < SIZE; ++i) {
		std::cin >> myarr[i];
		manage(myarr, i);
	}
	size_t j = SIZE;
	for (size_t i = 1; i <= SIZE; ++i) {
		int temp = myarr[1];
		myarr[1] = myarr[j];
		myarr[j--] = temp;
		heapsort(myarr, 1, j);
	}
	std::cout << "\n---Sorted Elements---\n";
	for (int i = 0; i < SIZE; ++i) {
		std::cout << myarr[i] << "\n";
	}
	std::cout << std::endl;
	return 0;
}

void manage(std::array<int, SIZE>& arr, int i) {
	int tmp;
	tmp = arr[i];
	while ((i > 1) && (arr[i / 2] < tmp)) {
		arr[i] = arr[i/2];
		i /= 2;
	}
	arr[i] = tmp;
}

void heapsort(std::array<int, SIZE>& arr, int i, size_t size) {
	int tmp, j;
	tmp = arr[i];
	j = i * 2;
	while (j <= size) {
		if ((j < size) && (arr[j] < arr[j + 1])) {
			j++;
		}
		if ((arr[j] < arr[j / 2])) { break; }
		arr[j / 2] = arr[j];
		j *= 2;
	}
	arr[j/2] = tmp;
}