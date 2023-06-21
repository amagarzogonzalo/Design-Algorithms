//Alejandro Magarzo Gonzalo, C82


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
T(n) = c0 si a = b && a2 = b2
	 = c1 + 4T(nxn/4) si a != b

T(n) = 4T(nxn/4) + c1
	 = 4(4(T(nxn/4^2) + c1) + c1 = 16T(nxn/4^2) + 5c1
	 = 4(16(T(nxn/4^3) + 5c1) + c1 = 64T(nxn/4^3) + 21c1
	 = 4^iT(nxn/4^i) + ic1
	 caso basico cuando 1 = nxn/4^i
	 por tanto iln4 = 2ln(n) -> i = 2ln(n)/ln4 = ln(n)
	 T(n) = c1 + 4T(nxn/4) = T(0) + log n c1 = c0 + log n c1 e O(log n)


*/


bool equi(std::vector<std::vector<int>> const & v, int &x, int a, int b, int a2, int b2) {
	if (a == b && a2 == b2) {
		return true;
	}
	else {
		int xiz = 1, xder = 1, j = a2;
		for (int i = a; i <= b; i++) {
			xiz = xiz * v[i][j];
			j++;
		}
		j = b2;
		for (int i = a; i <= b; i++) {
			xder = xder * v[i][j];
			j--;
		}
		if (xiz == xder) {
			int m = (a + b) / 2;
			bool equi1 = equi(v, x, a, m, a, m);
			bool equi2 = equi(v, x, a, m, m + 1, b);
			bool equi3 = equi(v, a, m + 1, b, a, m);
			bool equi4 = equi(v, a, m + 1, b, m + 1, b);
			x = xiz;
			return equi1 && equi2 && equi3 && equi4 && xiz == xder;
		}
		else return false;
	}
}



void resuelveCaso() {
	int n;
	cin >> n;
	std::vector<std::vector<int>> v(n);
	for (int i = 0; i < n; i++) {
		std::vector<int> aux(n);
		for (int j = 0; j < n; j++) {
			cin >> aux[j];
		}
		v[i] = aux;
	}
	int x = 0;
	if (n == 1) cout << "SI " << v[n - 1][n - 1] << endl;
	else {
		bool b = equi(v, x, 0, n - 1, 0, n-1);
		if (b) cout << "SI " << x << endl;
		else cout << "NO" << endl;
	}
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