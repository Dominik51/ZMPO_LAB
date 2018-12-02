#pragma once
#include <vector>
#include <random>
#include "CKnapsackProblem.h"
using namespace std;

class CIndividual
{
public:
	CIndividual();
	double dGetFitness();
	void vMutate(double i_mutatation_chance);
	vector<CIndividual> vCrossover(CIndividual c_individual);
	vector<int> vGetVGenotype();
	void vSetVGenotype(vector <int> v_genotype);
	void vSetCKnapsackProblem(CKnapsackProblem *c_knapsack_problem);

private:
	mt19937 gen;

	CKnapsackProblem *cKnapsackProblem;
	vector <int> vGenotype;
};