#pragma once
#include <vector>
#include <random>

using namespace std;

class CIndividual
{
public:
	CIndividual();
	//double iGetAdaptation();
	void vMutate(double i_mutatation_chance);
	vector<CIndividual> vCrossover(CIndividual c_individual);
	vector<int> vGetVGenotype();
	void vSetVGenotype(vector <int> v_genotype);
private:
	mt19937 gen;

	vector <int> vGenotype;
};