#include "CGeneticAlgorithm.h"
#include <iostream>
CGeneticAlgorithm::CGeneticAlgorithm()
{
	random_device rd;
	mt19937 generator(rd());
	gen = generator;

	cKnapsackProblem = nullptr;
	iPopulationSize = 2;
	dCrossoverChance = 0.5;
	dMutationChance = 0.5;
	iIterationsToStop = 10;
}

void CGeneticAlgorithm::vRun()
{
	vGeneratePopulation();
	for (int i = 0; i < iIterationsToStop; i++)
	{
		vector<CIndividual> vNewPopulation;
		while(vNewPopulation.size() < iPopulationSize)
		{
			uniform_int_distribution<> disInt(0, iPopulationSize - 1);
			uniform_real_distribution<> disReal(0, 1);

			int idx1 = disInt(gen);
			int idx2 = disInt(gen);
			int idxCIndividual1 = iChooseIndividual(idx1, idx2);
			idx1 = disInt(gen);
			idx2 = disInt(gen);
			int idxCIndividual2 = iChooseIndividual(idx1, idx2);
			if (dCrossoverChance <= disReal(gen))
			{
				vector<CIndividual> newCIndividuals = vPopulation.at(idxCIndividual1).vCrossover(vPopulation.at(idxCIndividual2));
				vNewPopulation.push_back(newCIndividuals.at(0));
				vNewPopulation.push_back(newCIndividuals.at(1));
			}
			else
			{
				vNewPopulation.push_back(vPopulation.at(idxCIndividual1));
				vNewPopulation.push_back(vPopulation.at(idxCIndividual2));
			}
		}
		for (int i = 0; i < iPopulationSize; i++)
		{
			vNewPopulation.at(i).vMutate(dMutationChance);
		}
		vPopulation = vNewPopulation;
		vFindBestIndividual();
	}
}

int CGeneticAlgorithm::iChooseIndividual(int i_idx1, int i_idx2)
{
	if (vPopulation.at(i_idx1).dGetFitness() >= vPopulation.at(i_idx2).dGetFitness())
	{
		return i_idx1;
	}
	else
	{
		return i_idx2;
	}
}

void CGeneticAlgorithm::vFindBestIndividual()
{
	int iBestIndividual = 0;
	int iBestAdaptation = vPopulation.at(0).dGetFitness();
	for (int i = 1; i < iPopulationSize; i++)
	{
		if (vPopulation.at(i).dGetFitness() > iBestAdaptation)
		{
			iBestAdaptation = vPopulation.at(i).dGetFitness();
			iBestIndividual = i;
		}
	}
	if (iBestAdaptation > cBestCIndividual.dGetFitness())
	{
		cBestCIndividual = vPopulation.at(iBestIndividual);
	}

	for (int i = 0; i < cBestCIndividual.vGetVGenotype().size(); i++)
	{
		cout << cBestCIndividual.vGetVGenotype().at(i) << ", ";
	}
	cout << " -- " << cBestCIndividual.dGetFitness() << endl;
}

bool CGeneticAlgorithm::vSetCKnapsackProblem(CKnapsackProblem *c_knapsack_problem)
{
	if (c_knapsack_problem != nullptr)
	{
		cKnapsackProblem = c_knapsack_problem;
		return true;
	}
	else
	{
		return false;
	}
}

bool CGeneticAlgorithm::bSetIPopulationSize(int i_population_size)
{
	if (i_population_size > 1)
	{
		iPopulationSize = i_population_size;
		return true;
	}
	else
	{
		return false;
	}
}

bool CGeneticAlgorithm::bSetDCrossoverChance(double d_crossover_chance)
{
	if (d_crossover_chance >= 0 && d_crossover_chance <= 1)
	{
		dCrossoverChance = d_crossover_chance;
		return true;
	}
	else
	{
		return false;
	}
}

bool CGeneticAlgorithm::bSetDMutationChance(double d_mutation_chance)
{
	if (d_mutation_chance >= 0 && d_mutation_chance <= 1)
	{
		dMutationChance = d_mutation_chance;
		return true;
	}
	else
	{
		return false;
	}
}

bool CGeneticAlgorithm::bSIIterationsToStop(int i_iterations_to_stop)
{
	if (i_iterations_to_stop > 0)
	{
		iIterationsToStop = i_iterations_to_stop;
		return true;
	}
	else
	{
		return false;
	}
}

vector<int> CGeneticAlgorithm::vGetBestSolution()
{
	return cBestCIndividual.vGetVGenotype();
}

void CGeneticAlgorithm::vGeneratePopulation()
{
	uniform_int_distribution<> disInt(0, 1);
	for (int i = 0; i < iPopulationSize; i++)
	{
		CIndividual cIndividual;
		vector<int> cIndividualGenotype;
		for (int j = 0; j < cKnapsackProblem->iGetNumberOfItems(); j++)
		{
			cIndividualGenotype.push_back(disInt(gen));
		}
		cIndividual.vSetVGenotype(cIndividualGenotype);
		cIndividual.vSetCKnapsackProblem(cKnapsackProblem);
		vPopulation.push_back(cIndividual);
	}
}


