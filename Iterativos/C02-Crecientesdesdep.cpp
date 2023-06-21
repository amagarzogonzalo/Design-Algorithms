// Alejandro Magarzo Gonzalo, C82

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool iterativo(std::vector <int> const &v, int n, int p) {
	if (p + 1 == n) return true;
	int max = v[0], j = 0, min = v[p + 1];
	while (j < n) {
		if (j <= p) { if (max < v[j]) max = v[j]; }
		else if (min > v[j]) min = v[j];
		j++;
	}
	return max < min;
}

void resuelveCaso() {
	int n, p;
	cin >> n >> p;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	bool b = iterativo(v, n, p);
	if(b)cout << "SI" << endl;
	else cout << "NO" << endl;
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