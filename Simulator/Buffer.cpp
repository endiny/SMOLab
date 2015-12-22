#include "stdafx.h"
#include "Buffer.h"

Buffer::Buffer(int n) {
	this->n = n;
	buff.resize(n, NULL);
	buffOrder.reserve(n);
	

}

Buffer::~Buffer() {}

Customer* Buffer::putAndReturnDenial(Customer* customer) {
	for (auto i = buff.begin(); i < buff.end(); i++)
	{
		if (*i == NULL) {
			*i = customer;
			buffOrder.push_back(i);
			return NULL;
		}
	}
	auto theOldestCustomer = buffOrder.front();
	buffOrder.erase(buffOrder.begin());
	buffOrder.push_back(theOldestCustomer);
	Customer* denial = *theOldestCustomer;
	*theOldestCustomer = customer;
	return denial;
}

Customer* Buffer::pop(int priority) {
	if (buffOrder.empty()) {
		return NULL;
	}

	reverse(buffOrder.begin(), buffOrder.end());

	auto iter = buffOrder.end();
	for (auto i = buffOrder.begin(); i < buffOrder.end(); i++)
	{
		if ((*(*i))->getSourceNo() == priority)
		{
			iter = i;
			break;
		}
		else if (iter == buffOrder.end())
		{
			iter = i;
		}
		else if ((*(*i))->getSourceNo() < (*(*iter))->getSourceNo())
		{
			iter = i;
		}
	}

	Customer* customer = (*(*iter));
	(*(*iter)) = NULL;
	buffOrder.erase(iter);
	reverse(buffOrder.begin(), buffOrder.end());
	return customer;
}


bool Buffer::isEmpty()
{
	return buffOrder.empty();
}

Customer* Buffer::back()
{
	return *(buffOrder.back());
}



void Buffer::print()
{
	for (int i = 0; i < n; i++)
	{
		if (buff[i] != NULL)
		{
			cout <<"    |"<< buff[i]->getSourceNo() << "-" << buff[i]->getArrivalTime() <<"|"<< endl;
		}
		else
		{
			cout << "    |NULL|" << endl;
		}
	}
}

vector<string> Buffer::getBuffer()
{
	vector<string> res(n, "");
	for (int i = 0; i < n; i++)
	{
		if (buff[i] != NULL)
		{
            res[i] += "Customer: " + to_string(buff[i]->getSourceNo()) + "-"+to_string(buff[i]->getNo());
		}
		else
		{
			res[i] += "-----";
		}
	}
	return res;
}





