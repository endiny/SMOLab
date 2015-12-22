#pragma once
class Simulator
{
private:
	int n;
	int i;
	bool appendix;
	bool working;
	Buffer* buffer;
	ArrivalProcess* ap;
	ServiceProcess* sp;
	Statistic* statistic;
	Customer* customer, *denial;
	double arrivalT, serviceT, t;
    vector<string> denials;

public:
	Simulator(int n, int a, int s, int b, double sourceIntensity, double minServerIntensity, double maxServerIntensity);
	~Simulator();
	void nextAPstep();
	void nextSPstep();
	void nextStep();
	void run();
	vector<string> getSourses();
	vector<std::__cxx11::string> getBuffer();
	vector<string> getServers();
    vector<string> getDenials();
	Statistic* getStatistic();
};

