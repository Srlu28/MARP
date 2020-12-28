#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include "Digrafo.h"

int bfs(Digrafo const& g, int const ini, int const fin) {
	std::queue<std::pair<int, int>> q;
	std::vector<bool> visited(10000);

	if (ini == fin) return 0;

	q.push({ ini, 0 });

	while (!q.empty()) {
		std::pair<int, int> aux = q.front();
		q.pop();
		++aux.second;
		visited[aux.first] = true;

		for (int w : g.ady(aux.first)) {
			if (w == fin) {
				return aux.second;
			}
			if (!visited[w]) {
				q.push({ w, aux.second });
				visited[w] = true;
			}
		}
	}
}

int main() {
	int const n = 10000;
	Digrafo g = Digrafo(n);
	for (int i = 0; i < n; ++i) {
		g.ponArista(i, (i + 1) % n);
		g.ponArista(i, (i * 2) % n);
		g.ponArista(i, (i / 3) % n);
	}

	int ini, fin;

	std::cin >> ini >> fin;

	while (std::cin) {
		std::cout << bfs(g, ini, fin) << '\n';
		
		std::cin >> ini >> fin;
	}
}