// Alejandro Magarzo Gonzalo

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


/*
 T(n) = c0 si a == b-1
		2T(n/2) + c1 si a != b-1

T(n) = 2T(n/2) + c1
	 = 2(2T(n/4) + c1) + c1 = 4T(n/4) + 3c1
	 = 2(T(n/8) + 3c1) + c1 = 8T(n/8) + 7c1
	 ...
	 = 2^iT(n/2^i) + (2^i -1)c1
	 para llegar al caso base n / 2^i = 1 por lo que: i = logn 
	 2^lognT(1) + (2^logn - 1)c1 = nc0 + (n-1)c1= T(n) pertenece O(n)
 
 */


int battlestar(std::vector<int> & v, int a, int b, int n) {
	if (a == b) return 0;
	else if (a == (b - 1)) {
		return 0;
	}
	else {
		int m = (a + b - 1) / 2;

		int izq = battlestar(v, a, m+1, n);
		int der = battlestar(v, m+1, b, n);

		int x = 0, i = a, j = m + 1;
		while (i < m + 1 && j < b) {
			if (v[i] > v[j]) {
				x += (m - i + 1);
				++j;
			}
			else ++i;
		}
		std::sort(v.begin() + a, v.begin() + b);
		return x + izq + der;
		
	}
}

bool resuelveCaso() {
	int n;
	cin >> n;
	//Leer caso de prueba: cin>>...

	if (!std::cin)
		return false;
	std::vector<int> v(n);
	
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	int coste = battlestar(v, 0, n, n);
	cout << coste << endl;
	/*for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}*/
	//Resolver problema
	//Escribir resultado
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