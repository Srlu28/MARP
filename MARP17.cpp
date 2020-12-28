#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include "Digrafo.h"

void repairEntry(Digrafo& g, std::unordered_map<int, int>& inDegree) {
	int E, v, w;
	std::cin >> E;
	while (E--) {
		std::cin >> v >> w;
		g.ponArista(v - 1, w - 1);
		++inDegree[w - 1];
	}
}

void dfs_aux(Digrafo const& g, std::unordered_map<int, int>& inDegree, std::vector<bool>& visited, std::vector<int>& revPostorder, int const& v) {
	visited[v] = true;
	revPostorder.push_back(v);
	for (int w : g.ady(v))
		if (!visited[w] && --inDegree[w] <= 0) dfs_aux(g, inDegree, visited, revPostorder, w);
	
}

std::vector<int> dfs(Digrafo const& g, std::unordered_map<int, int>& inDegree) {
	std::vector<bool> visited(g.V());
	std::vector<int> revPostorder;

	for (int v = 0; v < g.V(); ++v)
		if (!visited[v] && inDegree[v] <= 0)
			dfs_aux(g, inDegree, visited, revPostorder, v);

	return revPostorder;
}

int main() {
	int v;
	std::cin >> v;

	while (std::cin) {
		std::unordered_map<int, int> inDegree;
		Digrafo g(v);
		repairEntry(g, inDegree);

		auto aux = dfs(g, inDegree);
		if (aux.size() == v)
			for (int i : aux)
				std::cout << i + 1 << ' ';
		else std::cout << "Imposible";
		std::cout << '\n';

		std::cin >> v;
	}
}