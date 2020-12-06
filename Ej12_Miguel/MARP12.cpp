#include <iostream>
#include <vector>
#include <map>
#include "ConjuntosDisjuntos.h"

int main() {
	int fil, col;
	char c;

	std::cin >> fil >> col;
	while (std::cin) {
		int maxi = 0;
		std::map<std::pair<int, int>, int> black;

		for (int i = 0; i < fil; ++i)
			for (int j = 0; j < col; ++j) {
				std::cin >> c;
				if (c == '#') black[{i, j}] = black.size();
			}
		ConjuntosDisjuntos conj(black.size());
		for (auto it = black.begin(); it != black.end(); ++it) {
			if (black.count({ it->first.first - 1, it->first.second })) conj.unir(it->second, black[{it->first.first - 1, it->first.second}]);
			if (black.count({it->first.first, it->first.second - 1})) conj.unir(it->second, black[{it->first.first, it->first.second - 1}]);
		}
		for (int i = 0; i < black.size(); ++i) maxi = std::max(maxi, conj.cardinal(i));
		std::cout << conj.num_cjtos() << ' ' << maxi << '\n';

		std::cin >> fil >> col;
	}
}