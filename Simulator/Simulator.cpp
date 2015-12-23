#include "stdafx.h"
#include "Simulator.h"


Simulator::Simulator(int n, int a, int s, int b, double sourceIntensity, double minServerIntensity, double maxServerIntensity)
{
	this->n = n;
	buffer = new Buffer(b);
	ap = new ArrivalProcess(a, sourceIntensity);
	sp = new ServiceProcess(s, minServerIntensity, maxServerIntensity);
	statistic = new Statistic(a, s);
	arrivalT = 0;
	serviceT = 0;
	t = 0;
	i = 0;
	appendix = false;
	working = true;

}

void Simulator::nextAPstep()
{
    i++;
    t = arrivalT;
//	cout << "T: " << t << endl;
	customer = ap->getNewCustomer();
	//statistic.addCustomer(customer);
//	cout << "Customer: " << customer->getSourceNo() << " " << customer->getArrivalTime() << endl;
	denial = buffer->push(customer);
//	buffer->print();
	if (denial != NULL)
	{
//		cout << "    DENIAL: " << denial->getSourceNo() << " " << denial->getArrivalTime() << endl;
		statistic->handleDenial(denial);
        denials.insert(denials.begin(),to_string(denial->getSourceNo())+"-"+to_string(denial->getNo()));
	}
	else
	{
//		cout << "    DENIAL: NULL" << endl;
	}
	if (!sp->isFull())
	{
//		cout << "to Server:" << endl;
		sp->startService(buffer->pop(), t);
//		buffer->print();
//		sp->print();
	}
}

void Simulator::nextSPstep()
{
	t = serviceT;
//	cout << "T: " << t << endl;
//	cout << "Server: ";
//	cout << sp->getNextFree() << endl;
	customer = sp->stopService();
	statistic->handleCustomer(customer);
	if (!buffer->isEmpty())
	{
		sp->startService(buffer->pop(), t);
//		buffer->print();

	}
//	sp->print();
	if (sp->isFree() && appendix)
	{
		working = false;
	}
}
void Simulator::nextStep()
{
	if (!working) return;

	if (i >= n)
	{
		appendix = true;
	}

	serviceT = sp->getNextEventTime();

	if (!appendix)
	{
		arrivalT = ap->getNextEventTime();
		if (arrivalT <= serviceT)
		{
			nextAPstep();
			return;
		}
	}

	nextSPstep();
}

void Simulator::run()
{
	while (working) nextStep();
	statistic->analyze(t);
//	cout << t << endl;
//	statistic->print();
}

vector<string> Simulator::getSourses()
{
	return ap->getSources();
}

vector<string> Simulator::getBuffer()
{
	return buffer->getBuffer();
}

vector<string> Simulator::getServers()
{
	return sp->getServers();
}

vector<string> Simulator::getDenials()
{
    return denials;
}

Statistic* Simulator::getStatistic()
{
	return statistic;
}

Simulator::~Simulator()
{
	delete buffer;
	delete ap;
	delete sp;
	delete statistic;
}
