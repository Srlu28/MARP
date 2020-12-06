#include <iostream>
#include <functional>
#include <algorithm>
#include <queue>

struct tCliente {
	long int caja, time;

	bool operator >(tCliente const& u2) const {
		return this->time > u2.time || this->time == u2.time && this->caja > u2.caja;
	}
};

int main() {
	long int n, c, newCliente;

	std::cin >> n >> c;
	while (n && c) {
		std::priority_queue<tCliente, std::vector<tCliente>, std::greater<tCliente>> v;
		tCliente aux;

		while (n--) v.push({ n + 1, 0 });
		while (c--) {
			std::cin >> newCliente;
			aux = v.top();
			v.pop();
			aux.time += newCliente;
			v.push(aux);
		}
		std::cout << v.top().caja << '\n';

		std::cin >> n >> c;
	}
}