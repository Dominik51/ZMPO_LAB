#pragma once
#include "CKnapsackProblem.h"
#include "CIndividual.h"
#include <vector>
#include <random>
using namespace std;

class CGeneticAlgorithm
{
public:
	CGeneticAlgorithm();
	void vRun();
	bool vSetCKnapsackProblem(CKnapsackProblem *c_knapsack_problem);
	bool bSetIPopulationSize(int i_population_size);
	bool bSetDCrossoverChance(double d_crossover_chance);
	bool bSetDMutationChance(double d_mutation_chance);
	bool bSetIIterationsToStop(int i_iterations_to_stop);
	vector<int> vGetBestSolution();

private:
	void vGeneratePopulation();
	int iChooseIndividual(int i_idx1, int i_idx2);
	void vFindBestIndividual();

	mt19937 gen;

	CKnapsackProblem *cKnapsackProblem;
	int iPopulationSize;
	double dCrossoverChance;
	double dMutationChance;
	int iIterationsToStop;
	vector<CIndividual> vPopulation;
	CIndividual cBestCIndividual;

};