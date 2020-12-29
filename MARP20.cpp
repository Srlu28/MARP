#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include "ConjuntosDisjuntos.h"

int main() {
	int fil, col, maxi;
	char aux;

	std::cin >> fil >> col;
	while (std::cin) {
		std::map<std::pair<int, int>, int> black;
		long int n, x, y, tam;
		maxi = 0;

		for (int i = 0; i < fil; ++i)
			for (int j = 0; j < col; ++j) {
				std::cin.get(aux);
				if (aux != '#' && aux != ' ') std::cin.get(aux);
				if (aux == '#') black[{i, j}] = black.size();
			}

		std::cin >> n;

		ConjuntosDisjuntos c(black.size() + n);
		for (auto it = black.begin(); it != black.end(); ++it) {
			if (black.count({ it->first.first - 1, it->first.second })) c.unir(it->second, black[{it->first.first - 1, it->first.second}]);
			if (black.count({ it->first.first, it->first.second - 1 })) c.unir(it->second, black[{it->first.first, it->first.second - 1}]);
			if (black.count({ it->first.first - 1, it->first.second - 1 })) c.unir(it->second, black[{it->first.first - 1, it->first.second - 1}]);
			if (black.count({ it->first.first - 1, it->first.second + 1 })) c.unir(it->second, black[{it->first.first - 1, it->first.second + 1}]);
		}
		for (int i = 0; i < black.size(); ++i) maxi = std::max(maxi, c.cardinal(i));
		std::cout << maxi << ' ';

		while (n--) {
			std::cin >> x >> y;
			if (!black.count({ --x, --y })) {
				tam = black.size();
				black[{x, y}] = tam;
				if (black.count({ x - 1, y })) c.unir(tam, black[{x - 1, y}]);
				if (black.count({ x, y - 1 })) c.unir(tam, black[{x, y - 1}]);
				if (black.count({ x - 1, y - 1 })) c.unir(tam, black[{x - 1, y - 1}]);
				if (black.count({ x - 1, y + 1 })) c.unir(tam, black[{x - 1, y + 1}]);
				if (black.count({ x + 1, y })) c.unir(tam, black[{x + 1, y}]);
				if (black.count({ x + 1, y + 1})) c.unir(tam, black[{x + 1, y + 1}]);
				if (black.count({ x, y + 1})) c.unir(tam, black[{x, y + 1}]);
				if (black.count({ x + 1, y - 1})) c.unir(tam, black[{x + 1, y - 1}]);
			}
			maxi = std::max(maxi, c.cardinal(tam));
			std::cout << maxi << ' ';
		}
		std::cout << '\n';

		std::cin >> fil >> col;
	}
}