#include "stdafx.h"
#include "ArrivalProcess.h"


ArrivalProcess::ArrivalProcess(int n, double intensity)
{
	this->n = n;
	sources.resize(n);
	for (int i = 0; i < n; i++)
	{
		sources[i] = new Source(i, intensity);
		sources[i]->generateNewT();
		
	}
	sortByT();
	
}


ArrivalProcess::~ArrivalProcess()
{
	
}

double ArrivalProcess::getNextEventTime() {
	return sources[0]->getT();
}


Customer* ArrivalProcess::getNewCustomer()
{
	Customer* customer = sources[0]->getCustomer();
	sources[0]->generateNewT();
	sortByT();
	return customer;
}

vector<string> ArrivalProcess::getSources()
{
	sortByNo();
	//vector<Source*> result(sources);
	vector<string> result(n, "");
	for (int i = 0; i < n; i++)
	{
        result[i] += "No: " + to_string(i);
        result[i] += "\nCustomer: " + to_string(sources[i]->getCustomer()->getNo());
        result[i] += "\nTime: " + to_string(sources[i]->getT());
	}
	sortByT();
	return result;
}

void ArrivalProcess::sortByT()
{
	sort(sources.begin(), sources.end(), [](Source* a, Source* b) {return a->getT() < b->getT(); });
}

void ArrivalProcess::sortByNo()
{
	sort(sources.begin(), sources.end(), [](Source* a, Source* b) {return a->getNo() < b->getNo(); });
}



