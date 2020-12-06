#include <iostream>
#include <queue>

long int min_effort(std::priority_queue<long int, std::vector<long int>, std::greater<long int>>& v) {
    long int op1, op2, sum = 0;

    while (v.size() > 1) {
        op1 = v.top();
        v.pop();
        op2 = v.top();
        v.pop();
        sum += op1 + op2;
        v.push(op1 + op2);
    }
    return sum;
}

int main() {
    long int n, aux;

    std::cin >> n;

    while (n) {
        std::priority_queue<long int, std::vector<long int>, std::greater<long int>> v;

        for (long int i = 0; i < n; ++i) {
            std::cin >> aux;
            v.push(aux);
        }
        std::cout << min_effort(v) << "\n";

        std::cin >> n;
    }
}