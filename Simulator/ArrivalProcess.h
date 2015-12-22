#pragma once
class ArrivalProcess
{
private: 
	int n;
	vector<Source*> sources;
public:
	ArrivalProcess(int n, double intensity);
	~ArrivalProcess();

	double getNextEventTime();
	Customer* getNewCustomer();
	vector<string> getSources();
	void sortByT();
	void sortByNo();
};

