#pragma once
class Customer
{
private: 
	int sourceNo;
	double arrivalTime;
	double bufferTime;
	double serviceTime;
	int serverNo;
    int No;

public:
    Customer(int sourceNo, int No, double arrivalTime);
	~Customer();

	double getArrivalTime();

	int getSourceNo();
	int getNo();
	void setBufferTime(double bufferTime);
	double getBufferTime();
	void setServiceTime(double st);
	double getServiceTime();
	void setServerNo(int serverNo);
	int gerServerNo();

	
	
};

