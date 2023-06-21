// Alejandro Magarzo Gonzalo, c82

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void imp(std::vector<int> &v, int n) {
	int i = 0, pos = 0;
	while (i < n) {
		if (v[i] % 2 == 0) {
			v[pos] = v[i];
			pos++;
		}
		i++;
		// Función de cota: T: n - i
		// I: forall u, pos: 0 <= u <= pos <= i && v[u] % 2 = 0: V[pos] = v[u]
	} 
	v.resize(pos);
}

/*
Coste lineal respecto al tamño de entrada del vector, a n.
P: long(v) = n && v = V
proc imp(inout vector v, int n)
Q: forall u, pos: 0 <= u <= pos < n && v[u] % 2 = 0: V[pos] = v[u]
*/

bool resuelveCaso() {
	int n;
	cin >> n;

	if (n == -1 || !std::cin)
		return false;

	std::vector <int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	imp(v, n);
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;

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