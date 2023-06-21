//Alejandro Magarzo Gonzalo, c82

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


/*
T(n) =	c0 si ini+1 = fin
		T(n/2) + c1 si ini+1 != fin

T(n) = T(n/2) + c1
	 = T(n/4) + c1 + c1
	 = T(n/8) + c1 + c1 + c1
	 ...
	 = T(n/2^i) + ic1
	 = T(1) + c1logn = T(logn) pertenece O(logn)
	 para llegar al caso base n/2^i = 1 por lo que i = logn
*/


int bongo(std::vector<int> const& v, int num, int ini, int fin) {
	if (ini + 1 == fin) {
		if (num + ini == v[ini]) return v[ini];
		else return -1;
	}
	else {
		int m = (ini + fin) / 2;
		if (num + m < v[m]) return bongo(v, num, ini, m);
		else return bongo(v, num, m, fin);
	}
}


void resuelveCaso() {
	int n, num;
	cin >> n >> num;
	std::vector <int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int sol = bongo(v, num, 0, n);
	if (sol == -1) cout << "NO" << endl;
	else cout << sol << endl;
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