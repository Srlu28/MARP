#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <climits>

class MedianHeap {
	std::priority_queue<long int, std::vector<long int>, std::less<long int>> minors;
	std::priority_queue<long int, std::vector<long int>, std::greater<long int>> greaters;
	long int median = LONG_MAX;

public: 
	void push(long int const a) {
		if (a < median) minors.push(a);
		else greaters.push(a);

		balance();

		median = (minors.size() >= greaters.size() ? minors.top() : greaters.top());
	}
	long int pop() {
		long int ret;
		if (minors.empty() && greaters.empty()) throw std::domain_error("");
		else if (minors.size() >= greaters.size()) {
			ret = minors.top();
			minors.pop();
		}
		else {
			ret = greaters.top();
			greaters.pop();
		}
		return ret;
	}

private:
	void balance() {
		if (greaters.size() - minors.size() == 2) {
			long int aux = greaters.top();
			greaters.pop();
			minors.push(aux);
		}
		else if (minors.size() - greaters.size() == 2) {
			long int aux = minors.top();
			minors.pop();
			greaters.push(aux);
		}
	}
};