// main file

#include <iostream>
#include <cmath>
#include <array>
#define MAX 5

typedef std::array<std::array<char, MAX>, MAX> tarr2d;
typedef std::array<char, MAX> tarr;

tarr2d a;

void nqueen(int row, const size_t& nq);
int feasible(int row, size_t col, const size_t& nq);
int getmarkedcol(size_t row, const size_t& nq);
void printmatrix();

int main(int argc, char **argv) {
	size_t num_queens;
	std::cout << "Enter number of queens: " << std::endl;
	std::cin >> num_queens;
	for (size_t i = 0; i < num_queens; ++i) {
		for (size_t j = 0; j < num_queens; ++j) {
			a[i][j] = '.';
		}
	}
	nqueen(0, num_queens);
	return 0;
}

void nqueen(int row, const size_t& nq) {
	if (row < nq) {
		for (size_t i = 0; i < nq; ++i) {
			if (feasible(row, i, nq)) {
				a[row][i] = 'Q';
				nqueen(row + 1, nq);
				a[row][i] = '.';
			}
		}
	}
	else {
		std::cout << "\nThe solution is: \n";
		printmatrix();
	}
}

int feasible(int row, size_t col, const size_t& nq) {
	int tcol;
	for (size_t i = 0; i < nq; ++i) {
		tcol = getmarkedcol(i, nq);
		if (col == tcol || row - i == (col - tcol)) {
			return 0;
		}
	}
	return 1;
}

int getmarkedcol(size_t row, const size_t& nq) {
	for (size_t i = 0; i < nq; ++i) {
		if (a[row][i] == 'Q') {
			return i;
			break;
		}
	}
	return 0;
}

void printmatrix() {
	std::cout << "\n";
	for (const tarr& row: a) {
		for (const char& c: row) {
			std::cout << c << "\t";
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}