#include <iostream>
#include <queue>
#include "Time.h"

int main() {
	int N;
	std::cin >> N;
	while (N > 0) {
		Time aux;
		int h = 0, m = 0, ret = 0;
		std::priority_queue<Time, vector<Time>, std::greater<Time>> films;

		for(int i = 0; i < N; ++i) {
			std::cin >> aux;
			films.push(aux);
		}
		while (N--) {
			aux = films.top();
			films.pop();
			if (aux.hIni() > h || (aux.hIni() == h && aux.mIni() >= m)) {
				m = (aux.minutos() + 10) % 60;
				h = aux.hora() + ((aux.minutos() + 10) / 60);
				++ret;
			}
		}
		std::cout << ret << '\n';

		std::cin >> N;
	}
}