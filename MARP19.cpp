#include <iostream>
#include <queue>
#include <vector>
#include "Digrafo.h"

int bfs(Digrafo const& g, int const& n, int const& k) {
	std::vector<bool> visited(g.V());
	std::queue<std::pair<int, int>> q;

	q.push({ 0, 0 });
	visited[0] = true;

	while (!q.empty()) {
		std::pair<int, int> step = q.front();
		q.pop();
		int s = step.first, w;

		for (int i = 1; i <= k && s + i <= n * n - 1; ++i) {
			w = (g.ady(s + i).size() ? g.ady(s + i).at(0) : s + i);

			if (!visited[w]) {
				if (w == n * n - 1) return step.second + 1;
				else {
					q.push({ w, step.second + 1 });
					visited[w] = true;
				}
			}
		}
	}
}

int main() {
	int n, k, numS, numE, v, w;
	std::cin >> n >> k;
	while (n && k) {
		std::cin >> numS >> numE;
		Digrafo g(n * n);

		for (int i = 0; i < numS + numE; ++i) {
			std::cin >> v >> w;
			g.ponArista(v - 1, w - 1);
		}

		std::cout << bfs(g, n, k) << '\n';

		std::cin >> n >> k;
	}
}