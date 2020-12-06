#include <iostream>
#include <queue>
#include <vector>
#include <functional>

struct tUser {
    long int id, period, nextSend;

    bool operator >(tUser const& u2) const {
        return this->nextSend > u2.nextSend || this->nextSend == u2.nextSend && this->id > u2.id;
    }
};

int main() {
    long int n, k;

    std::cin >> n;
    while (n) {
        std::priority_queue<tUser, std::vector<tUser>, std::greater<tUser>> v;
        tUser aux;

        while (n--) {
            std::cin >> aux.id >> aux.period;
            aux.nextSend = aux.period;
            v.push(aux);
        }
        std::cin >> k;
        while (k--) {
            aux = v.top();
            v.pop();
            std::cout << aux.id << '\n';
            aux.nextSend += aux.period;
            v.push(aux);
        }
        std::cout << "---\n";

        std::cin >> n;
    }
}