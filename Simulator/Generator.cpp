#include "stdafx.h"
#include "Generator.h"
#include "math.h"
Generator::Generator(double intensity)
{
	this->intensity = intensity;
}

double Generator::getNext()
{
	double r = (double)rand() / (double)RAND_MAX;
	return -1.0 / intensity * log(r);
}

Generator::~Generator()
{
}
