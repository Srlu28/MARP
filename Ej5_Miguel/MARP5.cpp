#include <iostream>
#include <queue>
#include <vector>
#include <functional>

struct tPac {
	long int grav, time;
	std::string name;

	bool operator <(tPac const& u2) const {
		return this->grav < u2.grav || this->grav == u2.grav && this->time < u2.time;
	}
};

int main() {
	long int n;
	tPac aux;
	char c;

	std::cin >> n;
	while (n) {
		std::priority_queue<tPac, std::vector<tPac>, std::less<tPac>> v;
		while (n--) {
			std::cin >> c;
			if (c == 'I') {
				std::cin >> aux.name >> aux.grav;
				aux.time = n;
				v.push(aux);
			}
			else {
				std::cout << v.top().name << '\n';
				v.pop();
			}
		}
		std::cout << "---\n";
		std::cin >> n;
	}
}