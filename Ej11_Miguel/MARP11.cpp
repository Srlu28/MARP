#include <iostream>
#include <algorithm>
#include "ConjuntosDisjuntos.h"

int main() {
	int n, v, a, ini, fin;

	std::cin >> n;
	while (n--) {
		int ret = 0;
		std::cin >> v >> a;

		ConjuntosDisjuntos c(v);
		while (a--) {
			std::cin >> ini >> fin;
			c.unir(--ini, --fin);
		}
		while (v--) ret = std::max(ret, c.cardinal(v));
		std::cout << ret << '\n';
	}
}