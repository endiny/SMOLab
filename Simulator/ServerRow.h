#pragma once
class ServerRow
{
public:
	int serverNo;
	double utilization;
public:
	ServerRow(int serverNo, double utilization)
	{
		this->serverNo = serverNo;
		this->utilization = utilization;
	}
	~ServerRow();
};

