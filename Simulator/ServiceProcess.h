#pragma once
#include <limits>
class ServiceProcess
{
private:
	int n, freeNum, current, nextFree, count;
	vector<Server*> servers;
public:
	ServiceProcess(int n, double minIntensity, double maxIntensity);
	~ServiceProcess();

	bool startService(Customer* customer, double startT);
	bool isFull();
	bool isFree();
	void recognizeNextEvent();
	double getNextEventTime();
	Customer* stopService();
	int getNextFree();
	void setPriority(int priority);
	int getPriority();
	int recognizeNewCurrent();
	int getCurrent();
	void print();
	vector<string> getServers();
};

