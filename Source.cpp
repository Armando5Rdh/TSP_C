#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <random>
#include <numeric>
using namespace std;

vector<vector<int>> Arreglo(int popsize, int Nt) {

	vector<vector<int>> Pop;

	for (int i = 0; i < popsize; i++) {
		Pop.push_back(vector<int> (Nt+1));
		//vector<int> chrom;
		for (int j = 0; j <= Nt; j++) {
			/*int r = rand() % (Nt + 1);

			while (find(chrom.begin(), chrom.end(), r) != chrom.end()) {
				r = rand() % (Nt + 1);
			}
			chrom.push_back(r);*/
			Pop[i][j] = j;

		}
		//Pop.push_back(chrom);
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


/*Costo = []
for i in pop :
disT = 0
for j in range(len(pop[0]) - 1) :
	disT += distancias[i[j]][i[j + 1]]
	disT += distancias[i[0]][i[-1]]
	Costo.append(disT)
	return Costo*/
vector<float> FCostos(vector<vector<int>> pop, vector<vector<float>> distancias) {

	vector<float> costo(0);
	float disT;

	for (vector<int> i : pop) {

		disT = 0;
		for (int j = 0; j < i.size()-1; j++) {
			disT += distancias[i[j]][i[j + 1]];
		}
		disT += distancias[i[0]][i[i.size()-1]];
		costo.push_back(disT);
	}

	return costo;

}



int main() {

	int popsize = 4;
	int Nt = 4;

	// poblacion de enteros, sin repetir
	vector<vector<int>> pop = Arreglo(popsize, Nt);

	// Matriz provisional para pruebas
	vector<vector<float>> distancias = { {0, 10, 20, 30, 40}, {10, 0, 15, 25, 35}, {20, 15, 0, 14, 22}, {30, 25, 14, 0, 16}, {40, 35, 22, 16, 0} };

	// Calculo de costos
	vector<float> costos = FCostos(pop, distancias);

	//Impresion antes de acomodar por costos
	for (int i = 0; i < pop.size() ; i++) {

		for (int j = 0; j < pop[i].size() ; j++) {
			cout << pop[i][j] << " ";
		}
		cout << endl;
		cout << "Costo arreglo " << i + 1 << ": " << costos[i] << "\n\n";
	}

	Acomodar(pop, costos);

	cout << "------------------------------\n";
	//Impresion despues de acomodar por costos
	for (int i = 0; i < pop.size(); i++) {

		for (int j = 0; j < pop[i].size(); j++) {
			cout << pop[i][j] << " ";
		}
		cout << endl;
		cout << "Costo arreglo " << i + 1 << ": " << costos[i] << "\n\n";
	}

	return 0;
}