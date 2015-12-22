#include "stdafx.h"
#include "Source.h"


Source::Source(long No, double intensity)
{
	this->No = No;
	generator = new Generator(intensity);
	t = 0.0;
	customerCount = 0;
}


Source::~Source()
{
	delete generator;
}


double Source::getT()
{
	return t;
}

int Source::getNo() {
	return No;
}



double Source::generateNewT()
{
	customerCount++;
	t = t + generator->getNext();
	return t;
}

Customer* Source::getCustomer() {
    return new Customer(No, customerCount, t);
    customerCount++;
}
