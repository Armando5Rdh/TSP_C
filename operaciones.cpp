#include "operaciones.h"


vector<vector<int>> Arreglo(int popsize, int Nt) {

	vector<vector<int>> Pop;

	for (int i = 0; i < popsize; i++) {
		Pop.push_back(vector<int>(Nt + 1));

		for (int j = 0; j <= Nt; j++) {
			Pop[i][j] = j;

		}
		unsigned seed = chrono::system_clock::now().time_since_epoch().count();
		shuffle(Pop[i].begin(), Pop[i].end(), default_random_engine(seed));
	}
	return Pop;
}


void Acomodar(vector<vector<int>>& chrom, vector<float>& costo) {

	vector<float> aux1 = costo;
	vector<vector<int>> aux3 = chrom;

	vector<int> orden(costo.size());
	iota(orden.begin(), orden.end(), 0);
	sort(orden.begin(), orden.end(), [&](int i, int j) { return costo[i] < costo[j]; });

	for (int i = 0; i < costo.size(); i++) {
		costo[i] = aux1[orden[i]];
		chrom[i] = aux3[orden[i]];
	}

}


vector<float> FCostos(vector<vector<int>> pop, vector<vector<float>> distancias) {

	vector<float> costo(0);
	float disT;

	for (vector<int> i : pop) {

		disT = 0;
		for (int j = 0; j < i.size() - 1; j++) {
			disT += distancias[i[j]][i[j + 1]];
		}
		disT += distancias[i[0]][i[i.size() - 1]];
		costo.push_back(disT);
	}

	return costo;

}

float CalcularPromedio(vector<float> costos) {
	
	float suma = 0;
	for (float costo : costos) {
		suma += costo;
	}
	return (suma/costos.size());
}
