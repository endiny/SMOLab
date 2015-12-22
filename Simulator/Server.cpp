#include "stdafx.h"
#include "Server.h"


Server::Server(int No, double minIntensity, double maxIntensity)
{
	this->minIntensity = minIntensity;
	this->maxIntensity = maxIntensity;
	this->No = No;
	t = 0;
	free = true;
	priority = 0;
}


Server::~Server()
{
}

void Server::startService(Customer* customer, double startT)
{
	t = startT + (double)rand() / (double)RAND_MAX*(maxIntensity - minIntensity) + minIntensity;
	customer->setBufferTime(startT);
	customer->setServiceTime(t);
	customer->setServerNo(No);
	this->customer = customer;
	free = false;
}

Customer* Server::stopService()
{
	free = true;
	return customer;
}

bool Server::isFree()
{
	return free;
}

double Server::getT()
{
	return t;
}

void Server::print()
{
    cout << "------Server " << No << " : ";
	if (free)
	{
        cout << " Free ";
	}
	else
	{
        cout << customer->getSourceNo() << "-" << customer->getArrivalTime() << ": T: " << t;
	}
	cout << endl;

}

string Server::getCustomerNo()
{
    return to_string(customer->getSourceNo())+"-"+to_string(customer->getNo());
}

int Server::getPriority()
{
	return priority;
}

void Server::setPriority(int priority)
{
	this->priority = priority;
}
