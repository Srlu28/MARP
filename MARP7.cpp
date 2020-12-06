#include <iostream>
#include <functional>
#include <algorithm>
#include <set>

struct tPeriod {
	long int ini, fin;

	bool operator <(tPeriod const& p2) const {
		return this->fin <= p2.ini;
	}
	bool operator >(tPeriod const& p2) const {
		return this->ini >= p2.fin;
	}
	bool operator ==(tPeriod const& p2) {
		return (this->ini <= p2.ini && this->fin > p2.ini) || (this->ini < p2.fin && this->fin >= p2.fin) || (this->ini >= p2.ini && this->fin <= p2.fin);
	}
};

int main() {
	long int n, m, t, per;

	std::cin >> n >> m >> t;
	while (std::cin) {
		std::set<tPeriod> s;
		tPeriod aux;
		bool ok = true;

		while (n--) {
			std::cin >> aux.ini >> aux.fin;
			if (aux.ini < t) {
				aux.fin = std::min(aux.fin, t);
				auto ins = s.insert(aux);
				ok &= ins.second;
			}
		}
		while (m--) {
			std::cin >> aux.ini >> aux.fin >> per;
			while (ok && aux.ini < t) {
				auto ins = s.insert(aux);
				ok &= ins.second;

				aux.ini += per;
				aux.fin = std::min(aux.fin + per, t);
			}
		}
		std::cout << (ok ? "NO\n" : "SI\n");

		std::cin >> n >> m >> t;
	}
}