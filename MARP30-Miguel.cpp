#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

int main() {
	int N;
	std::cin >> N;

	while (N) {
		std::priority_queue<long int> tabla, esquiador;
		long int ret = 0, aux, t, e;

		for (int i = 0; i < N; ++i) {
			std::cin >> aux;
			esquiador.push(aux);
		}
		for (int i = 0; i < N; ++i) {
			std::cin >> aux;
			tabla.push(aux);
		}
		while (N--) {
			t = tabla.top();
			e = esquiador.top();
			tabla.pop();
			esquiador.pop();

			ret += abs(t - e);
		}
		std::cout << ret << '\n';

		std::cin >> N;
	}
}