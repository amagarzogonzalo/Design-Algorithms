// Alejandro Magarzo Gonzalo

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


/*
T(n) = c0 si a == b-1
	   T(n/2) + c1 si a != b-1

T(n) = T(n/2) + c1				 1
	 = T(n/4) + c1 + c1			 2
	 = T(n/8) + c1 + c1			 3
	 = ...
	 = T(n/2^i) + ic1			 i
	 = T(1) + lognc1 = c0 + lognc1 = T(logn) pertenece O(logn)	 
	 se llega a T(1), caso básico, si n / 2^i = 1 por lo que i = logn

*/

int minimo(std::vector<int> const& v, int a, int b) {
	if (a == b - 1) 
		return v[a];
	else {
		int m = (a + b) / 2;
		if (v[m] > v[a]) return minimo(v, a, m);
		else return minimo(v, m, b);
	}
	
}


bool resuelveCaso() {

	int n; cin >> n;

	if (!std::cin)
		return false;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];	
	int min = minimo(v, 0, n);
	cout << min << endl;
	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
