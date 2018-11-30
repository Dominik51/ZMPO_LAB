#include "CGeneticAlgorithm.h"

CGeneticAlgorithm::CGeneticAlgorithm()
{
}

void CGeneticAlgorithm::vRun()
{
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
	if (i_iterations_to_stop <= 0)
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
	return vector<int>();
}
