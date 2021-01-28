#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using pair = std::pair<long int, long int>;

int main() {
	long int N, aux1, aux2;
	std::cin >> N;

	while (N) {
		std::priority_queue<pair, std::vector<pair>, std::greater<pair>> e;
		std::pair<long int, long int> aux;
		long int mini = 0, ret = 0;

		while (N--) {
			std::cin >> aux1 >> aux2;
			e.push({ aux1, aux2 });
		}
		while (e.size()) {
			aux = e.top();
			e.pop();

			if (aux.first >= mini) {
				++ret;
				mini = aux.second;
			}
			else mini = std::min(mini, aux.second);
		}
		std::cout << ret << '\n';

		std::cin >> N;
	}
}