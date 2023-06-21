// Alejandro Magarzo Gonzalo
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

char fuga(std::vector<char> const & v, char ini, char fin, int i, int f) {
	if (i + 1 == f) {
		if (v[i] == ini) return v[i] + 1;
		else return v[i] - 1;

	}
	else {
		if (ini != v[i]) return ini;
		else if (fin != v[f - 1]) return fin;

		int m = (i + f ) / 2;
		if (v[m] - v[i] == m - i) return fuga(v, v[m], fin, m, f);
		else return fuga(v, ini, v[m - 1], i, m);
	}
}

void resuelveCaso() {
	char ini, fin;
	std::vector <char> v;
	cin >> ini >> fin;
	int n = fin - ini;
	for (int i = ini; i < n; i++) {
		cin >> v[i];
	}
	cout << fuga(v, ini, fin, 0, n) << endl;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}