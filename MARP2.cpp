#include <iostream>
#include <vector>

#include "TreeSet_AVL.h"

// Miguel Jesús Peñalver Carvajal

bool resuelveCaso() {
	int n, m, aux;
	Set<int> s;
	std::vector<int> consult;

	std::cin >> n;

	if (n == 0) return false;

	while (n--) {
		std::cin >> aux;
		s.insert(aux);
	}

	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		std::cin >> aux;
		consult.push_back(aux);
	}

	for (int i = 0; i < m; ++i) {
		try {
			std::cout << s.kesimo(consult[i]) << "\n";
		}
		catch (std::domain_error e) {
			std::cout << "??\n";
		}
	}

	std::cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}