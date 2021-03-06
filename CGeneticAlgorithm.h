#pragma once
#include "CKnapsackProblem.h"
#include "CIndividual.h"
#include <vector>
#include <random>
using namespace std;

const int DEFAULT_POPULATION_SIZE = 2;
const double DEFAULT_CROSS_CHANCE = 0.5;
const double DEFAULT_MUTATION_CHANCE = 0.5;
const int DEFAULT_ITERATIONS_TO_STOP = 10;
const double DEFAULT_BEST_GENOTYPE_FITNESS = -1;

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
	void vCrossPopulation(vector<CIndividual*> *v_population);
	void vMutatePopulation(vector<CIndividual*> *v_population);
	void vDeletePopulation();
	mt19937 gen;

	CKnapsackProblem *cKnapsackProblem;
	int iPopulationSize;
	double dCrossoverChance;
	double dMutationChance;
	int iIterationsToStop;
	vector<CIndividual*> vPopulation;
	vector<int> vBestGenotype;
	double iBestGenotypeFitness;
};