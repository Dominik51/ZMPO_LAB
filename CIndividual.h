#pragma once
#include <vector>

using namespace std;

class CIndividual
{
public:
	double iGetAdaptation();
	void vMutate();
	CIndividual cCrossover(CIndividual c_individual);
private:
	vector <double> genotype;
};