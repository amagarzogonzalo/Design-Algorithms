// Alejandro Magarzo Gonzalo, C82

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int rec(std::vector <int> const & v, int s, int a, int b) {
	if (a == b) return v[a];
	else if (b - a == 1) {
		if(abs(s - v[a]) <= abs(s - v[b])) return v[a];
		else return v[b];
	}
	else {
		int m = (a + b) / 2;
		if (abs(s) - abs(v[m]) == 0) return v[m];
		else {
			if (s <= v[m]) return rec(v, s, a, m);
			else return rec(v, s, m, b);
		}
	}
}


void resuelveCaso() {
	int n, s;
	cin >> s >> n ;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int x = rec(v, s, 0, n-1);
	cout << x << endl; 
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