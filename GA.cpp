#include "operaciones.h"
#include "GA.h"

void GA(int maxit, int popsize, float mutrate, float selection, int Nt) {

	int keep = (selection * popsize);
	float mincost = -9999999;
	vector<vector<int>> pop = Arreglo(popsize, Nt);

	//vector<vector<int>> pop = { {0,1,3,2,4},{4,2,1,3,0},{0,3,4,1,2},{3,2,4,1,0},{4,1,0,3,2},{4,3,2,0,1},{2,4,0,1,3},{2,4,0,3,1} };
	//vector<vector<float>> distancias = { {0, 10, 20, 30, 40}, {10, 0, 15, 25, 35}, {20, 15, 0, 14, 22}, {30, 25, 14, 0, 16}, {40, 35, 22, 16, 0} };
	vector<vector<float>> distancias = { {0.00,180.00,50.10,21.60,104.00},{178.00,0.00,131.00,192.00,236.00}, {50.20, 135.00, 0.00, 64.50, 108.00},{23.10, 194.00, 63.50, 0.00, 85.30},{105.00, 239.00, 109.00, 86.10, 0.00} };
	vector<float> costos = FCostos(pop, distancias);
	Acomodar(pop, costos);

	vector<float> minC;
	vector<float> meanC;

	minC.push_back(costos[0]);
	meanC.push_back(CalcularPromedio(costos));

	int iga = 0;

	while (iga < maxit) {
		iga++;
		int M = ceil((popsize - keep) / 2);

		double sum = 0;
		int a = popsize / 2;
		vector<double> prob;

		for (int i = 1; i < a + 1; i++) {
			prob.push_back(i);
			sum += prob[i - 1];

		}


		for (int i = 0; i < prob.size(); i++) {
			prob[i] = prob[i] / sum;
		}

		reverse(prob.begin(), prob.end());
		vector<double> odds = { 0 };
		double b = 0;

		for (double value : prob) {
			b += value;
			odds.push_back(b);
		}

		vector<double> pick1(M);
		vector<double> pick2(M);
		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<double> distribution(0.0, 1.0);
		for (int i = 0; i < M; i++) {
			pick1[i] = distribution(gen);
			pick2[i] = distribution(gen);
		}

		

		int ic = 0;
		vector<int> ma, pa;

		while (ic < M) {
			for (int id = 1; id <= keep; id++) {

				if (pick1[ic] <= odds[id] && pick1[ic] > odds[id - 1]) {
					ma.push_back(id - 1);
				}
				if (pick2[ic] <= odds[id] and pick2[ic] > odds[id - 1]) {
					pa.push_back(id - 1);
				}
			}
			ic += 1;
		}

		vector<int> ix;

		for (int i = 0; i < keep; i += 2) {
			ix.push_back(i);
		}

		for (int i = 0; i < ma.size(); i++) {
			vector<int> padre1 = pop[ma[i]];
			vector<int> padre2 = pop[pa[i]];
			vector<int> ciclos(padre1.size(), -1);
			int numCiclo = 1;

			auto cicloInicio = find(ciclos.begin(), ciclos.end(), -1);

			// Cruce cíclico
			while (cicloInicio != ciclos.end()) {
				int pos = cicloInicio - ciclos.begin();

				while (ciclos[pos] < 0) {
					ciclos[pos] = numCiclo;

					int valor = padre2[pos];
					pos = find(padre1.begin(), padre1.end(), valor) - padre1.begin();
				}

				numCiclo += 1;
				cicloInicio = find(ciclos.begin(), ciclos.end(), -1);
			}
			vector<int> hijo1(padre1.size());
			vector<int> hijo2(padre1.size());
			for (int i = 0; i < padre1.size(); ++i) {
				if (ciclos[i] % 2 == 0) {
					hijo1[i] = padre1[i];
					hijo2[i] = padre2[i];
				}
				else {
					hijo1[i] = padre2[i];
					hijo2[i] = padre1[i];
				}
			}

			pop[keep + ix[i]] = hijo1;
			pop[keep + ix[i] + 1] = hijo2;
		}

		int nmut = ceil((popsize - 1) * Nt * mutrate);
		vector<int> mrow;
		vector<int> mcol;
		vector<int> mcol2;

		uniform_real_distribution<double> distributionMut1(1.0, popsize - 1);
		uniform_real_distribution<double> distributionMut2(1.0, Nt - 1);

		for (int i = 0; i < nmut; i++) {
			mrow.push_back(ceil(distributionMut1(gen)));
			mcol.push_back(ceil(distributionMut2(gen)));
			mcol2.push_back(ceil(distributionMut2(gen)));
		}


		for (int i = 0; i < nmut; i++) {
			
			auto aux = pop[mrow[i]][mcol[i]];
			auto aux2 = pop[mrow[i]][mcol2[i]];
			pop[mrow[i]][mcol[i]] = aux2;
			pop[mrow[i]][mcol2[i]] = aux;

		}

		costos = FCostos(pop, distancias);
		Acomodar(pop, costos);
	}

	for (int i = 0; i < pop.size(); i++) {
		for (int j = 0; j < pop[i].size(); j++) {
			cout << pop[i][j];
		}
		cout << endl << costos[i] << endl << endl;;
	}
}
	
