#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <random>
#include <numeric>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;
using namespace chrono;

vector<vector<int>> Arreglo(int popsize, int Nt);
void Acomodar(vector<vector<int>>& chrom, vector<float>& costo);
vector<float> FCostos(vector<vector<int>> pop, vector<vector<float>> distancias);
float CalcularPromedio(vector<float> costos);
vector<vector<float>> LecturaDistancias(string file);