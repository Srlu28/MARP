#include <iostream>
#include <algorithm>
#include "ConjuntosDisjuntos.h"

int main() {
	long int n, m, p, us1, us2;

	std::cin >> n >> m;
	while (std::cin) {
		ConjuntosDisjuntos c(n);
		while (m--) {
			std::cin >> p;
			if (p) std::cin >> us1;
			for (int i = 1; i < p; ++i) {
				std::cin >> us2;
				c.unir(us1 - 1, us2 - 1);
			}
		}
		for (int i = 0; i < n; ++i) std::cout << c.cardinal(i) << ' ';
		std::cout << '\n';

		std::cin >> n >> m;
	}
}