#include <iostream>
#include <vector>
#include <unordered_map>
#include "Digrafo.h"

void repairEntry(Digrafo& g, std::unordered_map<int, int>& inDegree) {
	int E, v, w;
	std::cin >> E;
	while (E--) {
		std::cin >> v >> w;
		g.ponArista(v, w);
		++inDegree[w];
	}
}

int main() {
	int v;
	std::cin >> v;

	while (std::cin) {
		std::unordered_map<int, int> inDegree;
		bool found = false;
		Digrafo g(v);
		repairEntry(g, inDegree);

		for (auto node = inDegree.begin(); node != inDegree.end() && !found; ++node)
			if (node->second == g.V() - 1 && !g.ady(node->first).size()) {
				std::cout << "SI " << node->first << '\n';
				found = true;
			}
		if (!found) std::cout << "NO\n";

		std::cin >> v;
	}
}