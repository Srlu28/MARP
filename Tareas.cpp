#include <iostream>
#include <fstream>
#include <queue>
#include "Digrafo.h"

using namespace std;

void tareas(vector<bool>& marcado, vector<int>& sol, int v, Digrafo const& d, vector<int>& entradas, int& num) {
	marcado[v] = true;
	bool aux;
	int i;
	queue<int> q;
	sol.push_back(v);
	num++;
	q.push(v);
	while (!q.empty()) {
		int vertice = q.front(); q.pop();

		for (auto it : d.ady(vertice)) {
			entradas[it]--;
			if (entradas[it] == 0) {
				sol.push_back(it);
				num++;
				marcado[it] = true;
				q.push(it);
			}

		}
	}
}







bool resuelveCaso() {

	Digrafo d(cin);
	if (!cin) return false;
	vector<int> sol, entradas = d.entrada();
	vector<bool> marcado(d.V(), false);
	int num = 0;

	for (int i = 0; i < d.V(); i++) {
		if (entradas[i] == 0 && !marcado[i]) {
			tareas(marcado, sol, i, d, entradas, num);
		}
	}
	//cout << d << endl;
	if (num == d.V())
		for (auto it : sol) cout << it + 1 << " ";
	else cout << "Imposible";
	cout << endl;

	return true;
}


int main() {

	//ajustes para que cin extraiga directamente de un fichero

#ifndef DOMJUDGE
	std::ifstream in("Tareas.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	
	while (resuelveCaso()) {
		;
	}

	//para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE


}