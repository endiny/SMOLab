#include "stdafx.h"
#include "Poisson.h"


Poisson::Poisson()
{
	lambda = 0;
	k = 0;
}


Poisson::~Poisson()
{
}

int Poisson::fact(int n)
{
	int res = 1;
	for (int i = 2; i <= n; i++)
	{
		res *= i;
	}
	return res;
}

void Poisson::setLambda(float mlambda)
{
	lambda = mlambda;
}

void Poisson::reset()
{
	lambda = 1;
	k = 0;
}

float Poisson::next()
{
	k++;
	lambda++;
	return pow(lambda, k)*exp(-1 * lambda) / fact(k);
}