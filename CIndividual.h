#pragma once

using namespace std;

class CIndividual
{
public:
	int iGetAdaptation();
	void vMutate();
	CIndividual cCrossover(CIndividual c_individual);
private:
	int *genotype = nullptr;
};