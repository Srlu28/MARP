#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include "Grafo.h"

int bfs(Grafo const& g, std::unordered_set<int>& visit, int const ori) {
	std::queue<int> q;
	std::unordered_map<int, bool> mark;
	unsigned int markedTrue = 0;
	int visited = visit.size();

	visit.insert(ori);
	q.push(ori);

	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int w : g.ady(v)) {
			if (!visit.count(w)) {
				visit.insert(w);
				q.push(w);
				mark[w] = !mark[v];
				markedTrue += (mark[w] ? 1 : 0);
			}
			else if (mark[v] == mark[w]) throw std::domain_error("IMPOSIBLE\n");
		}
	}
	return std::min((unsigned int)(visit.size() - visited - markedTrue), markedTrue);
}

int next_node(Grafo const& g, std::unordered_set<int> const& vis) {
	for (int i = 0; i < g.V(); ++i) if (!vis.count(i)) return i;
	return -1;
}

void repairEntry(Grafo& g) {
	int E, v, w;
	std::cin >> E;
	while (E--) {
		std::cin >> v >> w;
		g.ponArista(v-1, w-1);
	}
}

int main() {
	int v;
	std::cin >> v;

	while (std::cin) {
		Grafo g(v);
		repairEntry(g);

		std::unordered_set<int> visit;
		int sum = 0;

		try {
			while (visit.size() != g.V())
				sum += bfs(g, visit, next_node(g, visit));
			std::cout << sum << '\n';
		} catch (std::domain_error& e) {
			std::cout << e.what();
		}
		std::cin >> v;
	}
}