#include "CKnapsackProblem.h"

CKnapsackProblem::CKnapsackProblem()
{
}

bool CKnapsackProblem::bSetDCapacity(double d_capacity)
{
	if (d_capacity > 0)
	{
		dCapacity = d_capacity;
		return true;
	}
	else
	{
		return false;
	}
}

bool CKnapsackProblem::vSetVItemsSize(vector<double> *v_items_size)
{
	if (v_items_size != nullptr)
	{
		vItemsSize = v_items_size;
		return true;
	}
	else
	{
		return false;
	}

}

bool CKnapsackProblem::vSetVItemsValue(vector<double>* v_items_value)
{
	if (v_items_value != nullptr)
	{
		vItemsValue = v_items_value;
		return true;
	}
	else
	{
		return false;
	}
}
