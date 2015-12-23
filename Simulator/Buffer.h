#pragma once
#include "Customer.h"
#include <QVector>
#include <algorithm>

using namespace std;
class Buffer
{
private:
	int size;
	QVector<Customer*> buff;
	int count;
public:
	Buffer(int size);
	~Buffer();
	Customer* push(Customer* customer);
	Customer* pop();
	void print();
	bool isEmpty();
	vector<string> getBuffer();
};

