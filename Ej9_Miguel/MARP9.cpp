#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

struct tInstrumento {
	long int mus, atr, musAtr;

	bool operator <(tInstrumento const& i2) const {
		return this->musAtr < i2.musAtr;
	}
	bool operator >(tInstrumento const& i2) const {
		return this->musAtr > i2.musAtr;
	}
};

int main() {
	long int n, p, aux;

	std::cin >> p >> n;
	while (std::cin) {
		std::priority_queue<tInstrumento, std::vector<tInstrumento>, std::less<tInstrumento>> v;

		p -= n;
		while (n--) {
			std::cin >> aux;
			v.push({aux, 1, aux});
		}
		while (p--) {
			tInstrumento aux2 = v.top();
			v.pop();
			v.push({ aux2.mus, aux2.atr + 1, (long int) std::ceil((((long double) aux2.mus)/(aux2.atr + 1))) });
		}
		std::cout << v.top().musAtr << '\n';

		std::cin >> p >> n;
	}
}