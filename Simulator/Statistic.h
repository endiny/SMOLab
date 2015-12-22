#pragma once
using namespace std;
class Statistic
{
private:
	int sourceN;
	int serverN;
	vector< vector<Customer*> > customers;
	vector<int> count;
	vector<int> denialCount;
	vector<double> serviceT;
	vector<double> bufferT;
	vector<double> stayInSystemT;
	vector<double> denialProbability;
	vector<double> serviceTD;
	vector<double> bufferTD;
	vector<SourceRow*> sourceTable;

	vector<double> utilization;
	vector<ServerRow*> serverTable;
	

	
public:
	Statistic(int sourceN, int serverN);
	~Statistic();
	void handleCustomer(Customer* customer);
	void handleDenial(Customer* denial);
	void print();
	void addBufferT(Customer* customer);
	void addServiceT(Customer* customer);
	void addStayInSystemT(Customer* customer);
	void addUtilization(Customer* customer);
	void analyze(double totalTime);
	vector<int> getCount();
	vector<double> getDenialProbability();
	vector<double> getBufferT();
	vector<double> getServiceT();
	vector<double> getStayInSystemT();
	vector<double> getBufferTD();
	vector<double> getServiceTD();
	vector<SourceRow*> getSourceTable();
	vector<ServerRow*> getServerTable();
	
};

