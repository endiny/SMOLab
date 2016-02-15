#pragma once
#include "Customer.h"
#include <QVector>
#include <algorithm>

using namespace std;
class Buffer
{
private:
	int m_size;
	QVector<Customer*> buff;
	int count;
public:
	Buffer(int m_size);
	~Buffer();
	Customer* push(Customer* customer);
	Customer* pop();
	void print();
	bool isEmpty();
	vector<string> getBuffer();
};

