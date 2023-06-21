//Alejandro Magarzo Gonzalo, c82


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool det(std::vector<int> const &v, int n) {
	bool b = true;
	int i = 0;
	while (i < n - 1) {
		if (v[i] >= v[i + 1]) b = false;
		i++;
		// T: n-i-1
		// b = (forall u: 0 <= u <= i+1: v[u]<v[u+1] 
	}
	return b;
}

/*
Coste: Lineal, O(n) respecto a n elementos.
P: 2 <= n <= long(v) < 100000
func (in vector v, in int n) return bool b
Q: b = (forall u: 0 <= u < n-1: v[u]<v[u+1]) 
*/

bool resuelveCaso() {

	int n;
	cin >> n;

	if (n == 0 || !std::cin)
		return false;

	std::vector <int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	bool b = det(v, n);
	if (!b) cout << "DESCONOCIDOS" << endl;
	else cout << "DALTON" << endl;
	return true;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	// Resolvemos
	while (resuelveCaso());


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}