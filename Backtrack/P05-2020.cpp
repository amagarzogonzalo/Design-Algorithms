//Alejandro Magarzo Gonzalo, c82


#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void bt(int mplayas, int ntrab, int limpias, std::vector<int> & basuraplayas,
	std::vector<std::vector<int>> const & recogetrab, int k, int &playaslimpiadas, int &playaslimpiadastemp, int& basuramax,
	int &basuramaxtemp, bool &haysolucion, int & basuraestimada, std::vector<int> const & mintrabrestantes) {
	for (int i = 0; i < mplayas; i++) {
		if (k == 0 && basuraplayas[i] == 0) playaslimpiadastemp++;
		else if(basuraplayas[i] > 0) {// && i == mplayas-1 || (i < mplayas-1 && basuraplayas[i] - recogetrab[k][i] >= 0)) {
			int loqueserecoge = 0;
			if (basuraplayas[i] - recogetrab[k][i] <= 0) loqueserecoge = basuraplayas[i];
			else loqueserecoge = recogetrab[k][i];
			basuramaxtemp += loqueserecoge;
			basuraplayas[i] = basuraplayas[i] - recogetrab[k][i];

			bool playalimpiada = false;
			if (basuraplayas[i] <= 0) {
				playaslimpiadastemp++;
				playalimpiada = true;
			}
			basuraestimada = mintrabrestantes[k] + basuramaxtemp;
			if (basuraestimada > basuramax || !haysolucion) {
				if (k == ntrab - 1) {
					if (playaslimpiadastemp >= limpias) {
						haysolucion = true;
						if (basuramax < basuramaxtemp || (basuramax == basuramaxtemp && playaslimpiadastemp > playaslimpiadas)) {
							basuramax = basuramaxtemp;
							playaslimpiadas = playaslimpiadastemp;
						}
					}
				}
				else {
					bt(mplayas, ntrab, limpias, basuraplayas, recogetrab, k + 1, playaslimpiadas, playaslimpiadastemp, basuramax,
						basuramaxtemp, haysolucion, basuraestimada, mintrabrestantes);
				}
			}

			if (playalimpiada) playaslimpiadastemp--;
			basuraplayas[i] = basuraplayas[i] + recogetrab[k][i];
			basuramaxtemp -= loqueserecoge;
		}
	}
}

void resuelveCaso() {
	int mplayas, ntrab, limpias;
	cin >> ntrab >> mplayas >> limpias;
	std::vector<int> basuraplayas(mplayas), mintrabrestantes(ntrab), minxtrab(ntrab);
	std::vector<std::vector<int>> recogetrab(ntrab);
	//std::vector<std::vector<int>> tuplatrabxplaya(mplayas);
	for (int i = 0; i < mplayas; i++) cin >> basuraplayas[i];
	for (int i = 0; i < ntrab; i++) {
		std::vector<int> tmp(mplayas);
		int min = 0;
		bool b = false;
		for (int j = 0; j < mplayas; j++) {
			cin >> tmp[j];
			if (!b || tmp[j] <= min) min = tmp[j];
			b = true;
		}
		minxtrab[i] = min;
		recogetrab[i] = tmp;
	}

	for (int i = 0; i < ntrab; i++) {
		int s = 0;
		for (int j = ntrab - 1; j >= i+1; j--) {
			s += minxtrab[j];
		}
		mintrabrestantes[i] = s;
	}
	bool haysolucion = false;
	int k = 0, playaslimpiadas = 0, basuramax = 0, playaslimpiadastemp = 0, basuramaxtemp = 0, basuraestimada = 0;
	bt(mplayas, ntrab, limpias, basuraplayas, recogetrab, k, playaslimpiadas, playaslimpiadastemp, basuramax, 
		basuramaxtemp, haysolucion, basuraestimada, mintrabrestantes);
	if (haysolucion) cout << basuramax << " " << playaslimpiadas << endl;
	else cout << "IMPOSIBLE" << endl;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("sample.in ");
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