#include "CIndividual.h"

CIndividual::CIndividual()
{
	random_device rd;
	mt19937 generator(rd());
	gen = generator;

	cKnapsackProblem = nullptr;
}

double CIndividual::dGetFitness()
{
	return cKnapsackProblem != nullptr ? cKnapsackProblem->dGetFintess(vGenotype) : 0;
}

void CIndividual::vMutate(double i_mutatation_chance)
{
	uniform_real_distribution<> disInt(0, 1);
	
	for (int i = 0; i < vGenotype.size(); i++)
	{
		if (i_mutatation_chance <= disInt(gen))
		{
			vGenotype.at(i) = (vGenotype.at(i) + 1) % 2;
		}
	}
}

vector<CIndividual> CIndividual::vCrossover(CIndividual c_individual)
{
	uniform_int_distribution<> disInt(1, vGenotype.size() - 1);
	int iCrossPoint = disInt(gen);

	vector <int> vGenotype1;
	vector <int> vGenotype2;

	for(int i = 0; i < iCrossPoint; i++)
	{
		vGenotype1.push_back(vGenotype.at(i));
		vGenotype2.push_back(c_individual.vGetVGenotype().at(i));
	}

	for (int i = iCrossPoint; i < vGenotype.size(); i++)
	{
		vGenotype1.push_back(c_individual.vGetVGenotype().at(i));
		vGenotype2.push_back(vGenotype.at(i));
	}

	vGenotype = vGenotype1;
	c_individual.vSetVGenotype(vGenotype2);
	vector<CIndividual> newCIndividuals;
	newCIndividuals.push_back(*this);
	newCIndividuals.push_back(c_individual);
	return newCIndividuals;
}

void CIndividual::vSetVGenotype(vector <int> v_genotype)
{
	vGenotype = v_genotype;
}

void CIndividual::vSetCKnapsackProblem(CKnapsackProblem * c_knapsack_problem)
{
	cKnapsackProblem = c_knapsack_problem;
}

vector<int> CIndividual::vGetVGenotype()
{
	return vGenotype;
}
