//Alejandro Magarzo Gonzalo c82


#include <fstream>
#include <vector>
#include <iostream>


using namespace std;

/*
P: 0<= n<= longitud(v)
func vectorPastoso(vector v, int n, inout x) return b
Q: b = (exists i: 0 <= i < n: v[i] = (sumatorio w: i+1 <= w < n: v[w])) &&
b => x = (max i: 0 <= i < n && v[i] = (sumatorio w: i+1 <= w < n: v[w]): i)

Cota: T: j


Caso peor: orden lineal O(n), n es el tamaño del vector de entrada, este caso se da cuando no es pastoso y se recorre todo el vector pero
no se encuentra ningun elemento que cumpla la condicion por lo que se recorre el bucle hasta llegar a la posición 0 sin éxito para encontrar
un elemento que cumpla la condición.
*/

void vectorPastoso(std::vector <int> &v, int n, int &x, bool & b) {
	x = n - 1; int suma = 0;
	while (x >= 0 && v[x] != suma) {
		// I: -1 <= x <= n-1 && forall l: 0 < p < n:!pastoso(v, k) && suma = (sumatorio j: x < j < n: v[j])
		// donde pastoso(v,k) = v[k] = sumatorio i: k < i < n: v[i]
		suma = suma + v[x];
		x = x - 1;

	}
	b = (x >= 0);
}



void resuelveCaso() {
	int n;
	cin >> n;
	std::vector <int> v(n);
	for (int i = 0; i < n; i++) {
		int a; cin >> a; v[i] = a;
	}
	int x; bool b = false;
	vectorPastoso(v, n, x, b);
	if (!b)  cout << "No" << endl;
	else cout << "Si " << x << endl;

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