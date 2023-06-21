//Alejandro Magarzo Gonzalo c82


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*
P: 0<= longitud(v) <= n && l > 1
proc heidi(in int v[], in int l, in int n, inout int secmax, inout, nllanos, inout int inillanos[])
Q: nllanos = (#p,q: 0 <= p <= q < n: esllano(v, p, q) && secmax = (max p,q: 0 <= p <= q < n && esllano(v,p,q): q-p) && 
(forall p,q:  0 <= p <= q < n && esllano(v,p,q): inillanos[nllanos] = n - p)
esllano(v,p,q) = (forall i, j: p <= i < j <= q: v[i] = v[j]) && (forall i: q <= i < n: v[q] > v[i]) && (p-q > l)

T: n-2 - j
I: -1 <= j<= n-2 && nllanos = (#p,q: j <= p <= q < n: esllano(v, p, q) && secmax = (max p,q: j <= p <= q < n && esllano(v,p,q): q-p) 
&& secparcial = (maxi: j <= i < n: v[i]) 

Coste: Coste lineal (O(n)).
*/

void heidi(std::vector<int> v, int l, int n, int& secmax, int& nllanos, std::vector<int>& inillanos) {
	int j = n - 2, secparcial = 0, maxder = v[n - 1], inill;
	secmax = 0;
	while (j >= 0) {
		if (v[j] == v[j + 1] && v[j] >= maxder) {
			if (secparcial == 0) {
				secparcial = 2;
				inill = j + 1;
			}
			else secparcial++;
		}
		if (secparcial > 0 && (v[j] != v[j + 1] || j == 0)) {
			if (secparcial >= l) {
				inillanos[nllanos] = inill;
 				nllanos++;
				if (secparcial > secmax) secmax = secparcial;
			}
			secparcial = 0;
		}
		if (maxder < v[j]) maxder = v[j];
		j--;
	}


}



bool resuelveCaso() {
	int n, l, a, secmax, nllanos = 0;
	cin >> n;
	if (cin.eof()) return false;
	cin >> l;
	std::vector <int> v(n), inillanos(n);
	for (int i = 0; i < n; i++) {
		cin >> a;
		v[i] = a;
	}
	heidi(v, l, n, secmax, nllanos, inillanos);
	cout << secmax << " " << nllanos << " ";
	for (int i = 0; i < nllanos; i++) cout << inillanos[i] << " ";
	cout << endl;
	return true;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	while(resuelveCaso());
	


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}