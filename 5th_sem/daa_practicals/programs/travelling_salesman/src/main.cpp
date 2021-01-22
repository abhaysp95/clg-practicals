// main file

#include <iostream>
#include <array>
#define SIZE 5

typedef std::array<std::array<int, SIZE>, SIZE> tmatrix;
typedef std::array<int, SIZE> tarr;

void minimum_cost(tmatrix& matrix, size_t city, tarr& visited_cities, int& cost, size_t& city_limit);
int tsp(tmatrix& matrix, int c, size_t& city_limit, tarr& visited_cities, int& cost);

int main(int argc, char **argv) {
	size_t city_limit{};
	int cost{};
	std::cout << "Enter total number of cities: " << std::endl;
	std::cin >> city_limit;
	tmatrix matrix;
	std::cout << "Enter Cost Matrix" << std::endl;
	for (tarr& row: matrix) {
		for (int& num: row) {
			std::cin >> num;
		}
	}
	tarr visited_cities;  // initialized all blocks to 0
	std::cout << "\nEntered Cost Matrix is:\n";
	for (const tarr& row: matrix) {
		for (const int& num: row) {
			std::cout << num << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\nPath: " << std::endl;
	minimum_cost(matrix, 0, visited_cities, cost, city_limit);
	std::cout << "\nMinimum cost: " << cost << std::endl;
	return 0;
}

void minimum_cost(tmatrix& matrix, size_t city, tarr& visited_cities, int& cost, size_t& city_limit) {
	size_t nearest_city{};
	visited_cities[city] = 1;
	std::cout << city + 1 << " " << std::endl;
	nearest_city = tsp(matrix, city, city_limit, visited_cities, cost);
	if (nearest_city == 999) {
		nearest_city = 0;
		std::cout << nearest_city + 1;
		cost += matrix[city][nearest_city];
		return;
	}
	minimum_cost(matrix, nearest_city, visited_cities, cost, city_limit);
}

int tsp(tmatrix& matrix, int c, size_t& city_limit, tarr& visited_cities, int& cost) {
	size_t nearest_city = 999, minimum = 999;
	int temp{};
	for (size_t count = 0; count <= city_limit; ++count) {
		if ((matrix[c][count] != 0) && (visited_cities[count] == 0)) {
			if (matrix[c][count] < minimum) {
				minimum = matrix[count][0] + matrix[c][count];
			}
			temp = matrix[c][count];
			nearest_city = count;
		}
	}
	if (minimum != 999) {
		cost += temp;
	}
	return nearest_city;
}