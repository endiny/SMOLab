#pragma once
class Server
{
private: 
	double deltaT, t;
	bool free;
	int No;
	Customer* customer;
	double minIntensity;
	double maxIntensity;
	int priority;
public:
	Server(int No, double minIntensity, double maxIntensity);
	~Server();

	void startService(Customer* customer, double startT);
	Customer* stopService();
	bool isFree();
	double getT();
	void print();
    string getCustomerNo();
	int getPriority();
	void setPriority(int priority);
};

