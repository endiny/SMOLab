#pragma once
#include "Customer.h"
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
class Buffer
{
private:
	int n;
	vector<Customer*> buff;
	vector<vector<Customer*>::iterator> buffOrder;
	int count;
public:
	Buffer(int n);
	~Buffer();
	Customer* putAndReturnDenial(Customer* customer);
	Customer* pop(int priority);
	void print();
	bool isEmpty();
	Customer* back();
	vector<string> getBuffer();
};

