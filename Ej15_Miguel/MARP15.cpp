#include <iostream>
#include <queue>
#include <unordered_set>
#include "Grafo.h"

void bfs(Grafo const& g, std::unordered_set<int>& visit, int const ori, int const ttl) {
	std::queue<std::pair<int, int>> q;

	visit.insert(ori);
	q.push({ ori, ttl });

	while (!q.empty()) {
		std::pair<int, int> v = q.front(); q.pop();

		if (v.second > 0)
			for (int w : g.ady(v.first)) {
				if (!visit.count(w)) {
					visit.insert(w);
					q.push({w, v.second - 1});
				}
			}
	}
}

void repairEntry(Grafo& g) {
	int E, v, w;
	std::cin >> E;
	while (E--) {
		std::cin >> v >> w;
		g.ponArista(v - 1, w - 1);
	}
}

int main() {
	int v, n, ini, ttl;
	std::cin >> v;

	while (std::cin) {
		Grafo g(v);
		repairEntry(g);
		
		std::cin >> n;
		while (n--) {
			std::unordered_set<int> visit;
			std::cin >> ini >> ttl;
			bfs(g, visit, --ini, ttl);
			std::cout << g.V() - visit.size() << '\n';
		}
		std::cout << "---\n";
		std::cin >> v;
	}
}