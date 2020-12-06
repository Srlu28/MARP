#include <iostream>

#include "bintree_eda.h"

// Miguel Jesús Peñalver Carvajal

typedef struct {
	bool balanced;
	int height;
}tInfo;

typedef struct {
	bool ok;
	long int mayor, menor;
}tNode;

tInfo wellBalanced(bintree<int> t) { // O(N), siendo N el número de nodos del árbol
	if (t.empty()) return { true, 0 };

	tInfo left = wellBalanced(t.left()), right = wellBalanced(t.right());

	if ((left.height == right.height || left.height + 1 == right.height || left.height == right.height + 1) && left.balanced == true && right.balanced == true)
		return { true, 1 + std::max(left.height, right.height) };

	else return { false, 0 };
}

tNode isBinarySearch(bintree<int> t) { // O(N), siendo N el número de nodos del árbol
	tNode ret = {true, t.root(), t.root()};

	if (!t.left().empty()) {
		tNode left = isBinarySearch(t.left());
		ret.ok = left.ok && left.mayor < t.root();
		ret.menor = left.menor;
	}

	if (!t.right().empty()) {
		tNode right = isBinarySearch(t.right());
		ret.ok = right.ok && right.menor > t.root() && ret.ok;
		ret.mayor = right.mayor;
	}

	return ret;
}

bool esAVL(bintree<int> t) {
	return (t.empty() || (wellBalanced(t).balanced && isBinarySearch(t).ok));
}

void resuelveCaso() {
	bintree<int> t;
	t = leerArbol(-1);

	std::cout << (esAVL(t) ? "SI\n" : "NO\n");
}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}