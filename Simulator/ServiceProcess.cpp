#include "stdafx.h"
#include "ServiceProcess.h"


ServiceProcess::ServiceProcess(int n, double minIntensity, double maxIntensity)
{
	this->n = n;
	freeNum = n;
	current = n-1;
	servers.resize(n);
	nextFree = -1;
	for (int i = 0; i < n; i++)
	{
		servers[i] = new Server(i, minIntensity, maxIntensity);
	}
	count = 0;
}




ServiceProcess::~ServiceProcess()
{
}

bool ServiceProcess::startService(Customer* customer, double startT)
{
	setPriority(customer->getSourceNo());
	recognizeNewCurrent();
	if (current >= 0)
	{	
		servers[current]->startService(customer, startT);
		count++;
		recognizeNextEvent();
		return true;
	}
	return false;
}

bool ServiceProcess::isFull()
{
	return count >= n;
}

bool ServiceProcess::isFree()
{
	return count <= 0;
}

void ServiceProcess::recognizeNextEvent() {
	int min = -1;
	for (int i = 0; i < n; i++)
	{
		if (!servers[i]->isFree())
		{
			if (min < 0)
			{
				min = i;
			}
			else
			{
				if (servers[i]->getT() < servers[min]->getT())
				{
					min = i;
				}
			}
		}
	}
	nextFree = min;
}

double ServiceProcess::getNextEventTime() {
	
	if (nextFree >= 0)
	{
		return servers[nextFree]->getT();
	}
    return std::numeric_limits<float>::max();
}

Customer* ServiceProcess::stopService()
{
	
	Customer* customer = servers[nextFree]->stopService();
	count--;
	recognizeNextEvent();
	return customer;
}

int ServiceProcess::getNextFree() {
	return nextFree;
}

int ServiceProcess::getPriority()
{
	return servers[current]->getPriority();
}

void ServiceProcess::setPriority(int priority)
{
	servers[current]->setPriority(priority);
}

void ServiceProcess::print()
{
	for (int i = 0; i < n; i++)
	{
		servers[i]->print();
	}
}

int ServiceProcess::recognizeNewCurrent()
{
	for (int i = current + 1; i < n; i++)
	{
		if (servers[i]->isFree())
		{
			current = i;
			return i;
		}
	}
	for (int i = 0; i <= current; i++)
	{
		if (servers[i]->isFree())
		{
			current = i;
			return i;
		}
	}
	return -1;
}

int ServiceProcess::getCurrent()
{
	return current;
}

vector<string> ServiceProcess::getServers()
{
	vector<string> res(n, "");
	for (int i = 0; i < n; i++)
	{
		res[i] += "No: " + to_string(i) + "\n";
		if (servers[i]->isFree())
		{
			res[i] += "FREE";
		}
		else
		{
            res[i] += "Customer: " + servers[i]->getCustomerNo() + "\nRelease time : " + to_string(servers[i]->getT());
		}
	}
	return res;
}


