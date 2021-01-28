#pragma once

#include <fstream>
#include <stdexcept>
#include <iomanip>
#include <iostream>

using namespace std;

class Time {
private:
	int HH; // Finishing time
	int MM;
	int h, m; // Begining time
	int DUR; // Duration

public:
	Time() {}

	Time(int hh, int mm, int dur) {
		DUR = dur;

		MM = (dur + mm) % 60;
		HH = hh + ((dur + mm) / 60);

		h = hh;
		m = mm;
	}

	~Time() {}

	// Observers
	int hora() const { return HH; }
	int minutos() const { return MM; }
	int hIni() const { return h; }
	int mIni() const { return m; }

	// Comparing operators
	bool operator<(Time const& h) const {
		return (HH * 60 + MM < h.HH * 60 + h.MM) || (HH * 60 + MM == h.HH * 60 + h.MM) && (DUR > h.DUR);
	}

	bool operator>(Time const& h) const {
		return (HH * 60 + MM > h.HH * 60 + h.MM) || (HH * 60 + MM == h.HH * 60 + h.MM) && (DUR > h.DUR);
	}

	bool operator==(Time const& h) const {
		return HH == h.HH && MM == h.MM && DUR == h.DUR;
	}

	// Read and write
	void read(std::istream& input = std::cin) {
		int h, m, s;
		char c;

		input >> h >> c >> m >> s;
		*this = Time(h, m, s);
	}
};

inline istream& operator>>(istream& in, Time& h) {
	h.read(in);
	return in;
}