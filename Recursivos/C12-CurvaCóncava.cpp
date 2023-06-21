// Alejandro Magarzo Gonzalo c82

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int min(std::vector<int> v, int a, int b) {
	if (a == b) {
		return v[a];
	}
	else {
		int m = (a + b) / 2;
		if (v[m] < v[m + 1]) return min(v, a, m);
		else return min(v, m+1, b);
		
	}
}


bool resuelveCaso() {
	int n, a;
	cin >> n;
	if (!std::cin)
		return false;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> a;
		v[i] = a;
	}
	int res = min(v,0, n-1);
	cout << res << endl;
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