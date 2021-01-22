// main file

#include <iostream>
#include <array>
#define MAX 5

typedef std::array<std::array<int, MAX>, MAX> tarr2d;
typedef std::array<int, MAX> tarr;

typedef struct {
	int u, v, w;
} edge;

typedef struct {
	edge data[MAX];
	int n;
} edgelist;

edgelist elist; // declaring and initializing edgelist

tarr2d G;
size_t n{};

edgelist spanlist;

void apply_kruskal();
void print_result();
void sort();
int find(const tarr& belongs, int vertexno);
void union1(tarr& belongs, int c1, int c2);

int main(int argc, char **argv) {
	//size_t num_vertices;
	//std::cout << "Enter number of vertices: " << std::endl;
	//std::cin >> num_vertices;
	std::cout << "Enter adjecency matrix: " << std::endl;
	for (tarr& row: G) {
		for (int& num: row) {
			std::cin >> num;
		}
	}
	apply_kruskal();
	print_result();
	return 0;
}

void apply_kruskal() {
	tarr belongs;
	int cno1{}, cno2{};
	elist.n = 0;

	for (size_t i = 1; i < n; ++i) {
		for (size_t j = 0; j < i; ++j) {
			if (G[i][j] != 0) {
				elist.data[elist.n].u = i;
				elist.data[elist.n].v = j;
				elist.data[elist.n].w = G[i][j];
				elist.n++;
			}
		}
	}
	sort();

	for (size_t i = 0; i < n; ++i) {
		belongs[i] = i;
	}
	spanlist.n = 0;

	for (size_t i = 0; i < n; ++i) {
		cno1 = find(belongs, elist.data[i].u);
		cno2 = find(belongs, elist.data[i].v);
		if (cno1 != cno2) {
			spanlist.data[spanlist.n] = elist.data[i];
			spanlist.n++;
			union1(belongs, cno1, cno2);
		}
	}
}

int find(const tarr& belongs, int vertexno) {
	return belongs[vertexno];
}

void union1(tarr& belongs, int c1, int c2) {
	for (size_t i = 0; i < n; ++i) {
		if (belongs[i] == c2) {
			belongs[i] = c1;
		}
	}
}

void sort() {
	edge temp;

	for (size_t i = 1; i < elist.n; ++i) {
		for (size_t j = 0; j < elist.n - 1; ++j) {
			if (elist.data[j].w > elist.data[j + 1].w) {
				temp = elist.data[j];
				elist.data[j] = elist.data[j + 1];
				elist.data[j + 1] = temp;
			}
		}
	}
}

void print_result() {
	int cost = 0;
	for (size_t i = 0; i < spanlist.n; ++i) {
		std::cout << spanlist.data[i].u << "\t"
			<< spanlist.data[i].v << "\t"
			<< spanlist.data[i].w << "\n";
		cost += spanlist.data[i].w;
	}
	std::cout << "\nCost of the spanning tree: " << cost << std::endl;
}