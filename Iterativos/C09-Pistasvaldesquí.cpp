//Alejandro Magarzo Gonzalo c82


#include <fstream>
#include <vector>
#include <iostream>


using namespace std;

/*
P: 0 <= n <= longitud(v)
proc pistas(in int v[], in int n, out int x)
Q: x = (max p,q: 0<= p < q <= n && espista(v,p,q) : q-p)
donde espista(v,p,q) = forall i, j: p <= i < j < q: v[i] >= v[j]
T: (n-1)- i
I: 0 <= i <= n-1 && x = (max p,q: 0<= p < q <= i+1 && espista(v,p,q) : q-p) && s = (exists w, u :0<= w < u <= i+1 && espista(v,w,u) : u-w)
*/

void pistas(std::vector <int> &v, int n, int &x) {
	int i = 0, s = 1;
	while (i < n-1) {
		if (v[i] >= v[i + 1]) 
			s++;
		else if (s >  1) 
			s = 1;

		if (s > x) x = s;
		i++;
	}
	if (s > x && n > 0) x = s;

}


void resuelveCaso() {
	int n;
	cin >> n;
	std::vector <int> v(n);
	for (int i = 0; i < n; i++) {
		int a; cin >> a; v[i] = a;
	}
	int x = 0;
	pistas(v, n, x);
	cout << x << endl;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int numCasos = 0;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}