#pragma once
class SourceRow
{
public:
	int sourceNo;
	int count;
	double denialProbability;
	double bufferT;
	double serviceT;
	double stayInSystemT;
	double bufferTD;
	double serverTD;
public:
	SourceRow(int sourceNo,
	int count,
	double denialProbability,
	double bufferT,
	double serviceT,
	double stayInSystemT,
	double bufferTD,
	double serverTD)
	{
		this->sourceNo = sourceNo;
		this->count = count;
		this->denialProbability = denialProbability;
		this->bufferT = bufferT;
		this->serviceT = serviceT;
		this->stayInSystemT = stayInSystemT;
		this->bufferTD = bufferTD;
		this->serverTD = serverTD;
	}

	
	~SourceRow();
};

