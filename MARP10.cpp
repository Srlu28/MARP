#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <stack>
#include "Grafo.h"

int main() {
	Grafo g(std::cin);

	while (std::cin) {
		std::unordered_set <int> visit;
		std::stack<int> adjacents;
		std::vector<int> from;
		bool cycle = false;

		from.resize(g.V());
		visit.insert(0);
		adjacents.push(0);

		while (!cycle && adjacents.size()) {
			int adj = adjacents.top();
			adjacents.pop();

			for (int aux : g.ady(adj)) {
				if (!visit.count(aux)) {
					visit.insert(aux);
					from[aux] = adj;
					adjacents.push(aux);
				}
				else if (from[adj] != aux) cycle = true;
			}
		}
		std::cout << (visit.size() == g.V() && !cycle ? "SI\n" : "NO\n");

		g = Grafo(std::cin);
	}
}