#include <iostream>
#include "MedianHeap.h"

int main() {
	long int n, aux;

	std::cin >> n;
	while (std::cin) {
		MedianHeap v;

		while (n--) {
			std::cin >> aux;

			if (aux != 0) v.push(aux);
			else {
				try {
					std::cout << v.pop() << ' ';
				}
				catch (std::domain_error& e) {
					std::cout << "ECSA ";
				}
			}
		}
		std::cout << '\n';
		std::cin >> n;
	}
}