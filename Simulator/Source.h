#pragma once
class Source
{
private:
	Generator* generator;
	long No;
	double t;
	int customerCount;
	
public:
	Source(long No, double intensity);
	~Source();

	double getT();
	int getNo();
	double generateNewT();
	Customer* getCustomer();
	void addDenial();


};

