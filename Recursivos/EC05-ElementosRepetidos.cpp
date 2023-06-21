// Alejandro Magarzo Gonzalo, C82

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

bool disperso(int a, int b, std::vector<int> const & v, int k) {
	if (a + 1 == b) return true;
	if (a + 2 == b) return std::abs(v[a] - v[b-1]) >= k;
	else {
		int m = (a + b) / 2;
		bool dispersoIzq = disperso(a, m, v, k);
		bool dispersoDer = disperso(m, b, v, k);
		return (dispersoIzq && dispersoDer) && std::abs(v[a] - v[b - 1]) >= k;
	}
}



bool resuelveCaso() {
	int n, k, a;
	cin >> n;
	if (!std::cin)
		return false;
	cin >> k;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) 
		cin >> v[i];
	
	bool b = disperso(0, n, v, k);
	if (b) cout << "SI" << endl;
	else cout << "NO" << endl;	
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