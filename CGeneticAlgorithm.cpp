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
	iBestGenotypeFitness = -1;
}

void CGeneticAlgorithm::vRun()
{
	if (cKnapsackProblem != nullptr)
	{
		vGeneratePopulation();
		for (int i = 0; i < iIterationsToStop; i++)
		{
			vFindBestIndividual();
			vector<CIndividual*> vNewPopulation;
			vCrossPopulation(&vNewPopulation);
			vMutatePopulation(&vNewPopulation);
			vDeletePopulation();
			vPopulation = vNewPopulation;
		}
		vDeletePopulation();
	}
}

void CGeneticAlgorithm::vCrossPopulation(vector<CIndividual*> *v_new_population)
{
	while (v_new_population->size() < iPopulationSize)
	{
		uniform_int_distribution<> disInt(0, iPopulationSize - 1);
		uniform_real_distribution<> disReal(0, 1);

		int idxCIndividual1 = iChooseIndividual(disInt(gen), disInt(gen));
		int idxCIndividual2 = iChooseIndividual(disInt(gen), disInt(gen));

		if (dCrossoverChance <= disReal(gen))
		{
			vector<CIndividual*> newCIndividuals = vPopulation.at(idxCIndividual1)->vCrossover(vPopulation.at(idxCIndividual2));
			v_new_population->push_back(newCIndividuals.at(0));
			v_new_population->push_back(newCIndividuals.at(1));
		}
		else
		{
			CIndividual *cNewIndividual1 = new CIndividual;
			CIndividual *cNewIndividual2 = new CIndividual;
			cNewIndividual1->vSetVGenotype(vPopulation.at(idxCIndividual1)->vGetVGenotype());
			cNewIndividual1->vSetCKnapsackProblem(cKnapsackProblem);

			cNewIndividual2->vSetVGenotype(vPopulation.at(idxCIndividual2)->vGetVGenotype());
			cNewIndividual2->vSetCKnapsackProblem(cKnapsackProblem);

			v_new_population->push_back(cNewIndividual1);
			v_new_population->push_back(cNewIndividual2);
		}
	}
}

void CGeneticAlgorithm::vMutatePopulation(vector<CIndividual*> *v_new_population)
{
	for (int i = 0; i < iPopulationSize; i++)
	{
		v_new_population->at(i)->vMutate(dMutationChance);
	}
}

void CGeneticAlgorithm::vDeletePopulation()
{
	while (!vPopulation.empty()) {
		delete vPopulation.back();
		vPopulation.pop_back();
	}
}

int CGeneticAlgorithm::iChooseIndividual(int i_idx1, int i_idx2)
{
	if (vPopulation.at(i_idx1)->dGetFitness() >= vPopulation.at(i_idx2)->dGetFitness())
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
	int iBestAdaptation = vPopulation.at(0)->dGetFitness();
	for (int i = 1; i < iPopulationSize; i++)
	{
		if (vPopulation.at(i)->dGetFitness() > iBestAdaptation)
		{
			iBestAdaptation = vPopulation.at(i)->dGetFitness();
			iBestIndividual = i;
		}
	}
	if (iBestAdaptation > iBestGenotypeFitness)
	{
		vBestGenotype = vPopulation.at(iBestIndividual)->vGetVGenotype();
		iBestGenotypeFitness = cKnapsackProblem->dGetFintess(vBestGenotype);
	}
	for (int i = 0; i < vBestGenotype.size(); i++)
	{
		cout << vBestGenotype.at(i) << ", ";
	}
	cout << " -- " << iBestGenotypeFitness << endl;
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

bool CGeneticAlgorithm::bSetIIterationsToStop(int i_iterations_to_stop)
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
	return vBestGenotype;
}

void CGeneticAlgorithm::vGeneratePopulation()
{
	uniform_int_distribution<> disInt(0, 1);
	for (int i = 0; i < iPopulationSize; i++)
	{
		CIndividual *cIndividual = new CIndividual;
		vector<int> cIndividualGenotype;
		for (int j = 0; j < cKnapsackProblem->iGetNumberOfItems(); j++)
		{
			cIndividualGenotype.push_back(disInt(gen));
		}
		cIndividual->vSetVGenotype(cIndividualGenotype);
		cIndividual->vSetCKnapsackProblem(cKnapsackProblem);
		vPopulation.push_back(cIndividual);
	}
	for (int i = 0; i < vPopulation.size(); i++)
	{
		cout << vPopulation.at(i)->dGetFitness() << endl;
	}
}


