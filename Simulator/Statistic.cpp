#include "stdafx.h"
#include "Statistic.h"




Statistic::Statistic(int sourceN, int serverN)
{
	this->sourceN = sourceN;
	this->serverN = serverN;
	count.resize(sourceN, 0);
	denialCount.resize(sourceN, 0);
	serviceT.resize(sourceN, 0);
	bufferT.resize(sourceN, 0);
	stayInSystemT.resize(sourceN, 0);
	denialProbability.resize(sourceN, 0);
	serviceTD.resize(sourceN, 0);
	bufferTD.resize(sourceN, 0);
	customers.resize(sourceN);
	sourceTable.resize(sourceN);

	utilization.resize(serverN);
	serverTable.resize(serverN);
}


Statistic::~Statistic()
{
}


void Statistic::handleCustomer(Customer* customer)
{
	count[customer->getSourceNo()]++;
	addBufferT(customer);
	addServiceT(customer);
	addStayInSystemT(customer);
	addUtilization(customer);
	customers[customer->getSourceNo()].push_back(customer);
}

void Statistic::handleDenial(Customer* denial)
{
	count[denial->getSourceNo()]++;
	denialCount[denial->getSourceNo()]++;
	delete denial;

}

void Statistic::print()
{
	cout << "No" << "   " << "CO" << "   " << "DP" << "   " << "BT" << "   " << "ST" << "   " << "SST" << "   " << "BTD" << "   " << "STD" << endl;
	for (int i = 0; i < sourceN; i++)
	{
		cout << i << "    " << count[i] << "    " << denialProbability[i] << "    " << bufferT[i] << "    " << serviceT[i] << "     " << stayInSystemT[i] << "     " << bufferTD[i] << "     " << serviceTD[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < serverN; i++)
	{
		cout << i << "   " << utilization[i] << endl;
	}
}

void Statistic::addBufferT(Customer* customer)
{
	bufferT[customer->getSourceNo()] += customer->getBufferTime() - customer->getArrivalTime();
}

void Statistic::addServiceT(Customer* customer)
{
	serviceT[customer->getSourceNo()] += customer->getServiceTime() - customer->getBufferTime();
}

void Statistic::addStayInSystemT(Customer* customer)
{
	stayInSystemT[customer->getSourceNo()] += customer->getServiceTime() - customer->getArrivalTime();
}

void Statistic::addUtilization(Customer* customer)
{
	utilization[customer->gerServerNo()] += customer->getServiceTime() - customer->getBufferTime();
}

void Statistic::analyze(double totalTime)
{
	for (int i = 0; i < sourceN; i++)
	{
		if (count[i] != 0)
		{
			denialProbability[i] = (float)denialCount[i] / count[i];
			bufferT[i] /= count[i];
			serviceT[i] /= count[i];
            stayInSystemT[i] /= count[i];
		}

		else
		{
			denialProbability[i] = 0;
			bufferT[i] = 0;
			serviceT[i] = 0;
            stayInSystemT[i] = 0;
		}
	}

	for (int i = 0; i < sourceN; i++)
	{
		if (count[i] > 1)
		{
            for(int j=0; j< customers[i].size(); j++)
			{
                double b = customers[i].at(j)->getBufferTime() - customers[i].at(j)->getArrivalTime() - bufferT[i];
                double s = customers[i].at(j)->getServiceTime() - customers[i].at(j)->getBufferTime() - serviceT[i];
				bufferTD[i] += b*b;
				serviceTD[i] += s*s;
			}
			bufferTD[i] /= (count[i] - 1);
			serviceTD[i] /= (count[i] - 1);
		}
		else
		{
			bufferTD[i] = 0;
			serviceTD[i] = 0;
		}

	}

	for (int i = 0; i < sourceN; i++)
	{
		sourceTable[i] = new SourceRow(i, count[i], denialProbability[i], bufferT[i],
			serviceT[i], stayInSystemT[i], bufferTD[i], serviceTD[i]);
	}

	for (int i = 0; i < serverN; i++)
	{
		utilization[i] /= totalTime;
	}

	for (int i = 0; i < serverN; i++)
	{
		serverTable[i] = new ServerRow(i, utilization[i]);
	}
}

vector<int> Statistic::getCount()
{
	return vector<int>(count);
}

vector<double> Statistic::getDenialProbability()
{
	return vector<double>(denialProbability);
}

vector<double> Statistic::getBufferT()
{
	return vector<double>(bufferT);
}

vector<double> Statistic::getServiceT()
{
	return vector<double>(serviceT);
}

vector<double> Statistic::getStayInSystemT()
{
	return vector<double>(stayInSystemT);
}

vector<double> Statistic::getBufferTD()
{
	return vector<double>(bufferTD);
}

vector<double> Statistic::getServiceTD()
{
	return vector<double>(serviceTD);
}

vector<SourceRow*> Statistic::getSourceTable()
{
	return vector<SourceRow*>(sourceTable);
}

vector<ServerRow*> Statistic::getServerTable()
{
	return vector<ServerRow*>(serverTable);
}
