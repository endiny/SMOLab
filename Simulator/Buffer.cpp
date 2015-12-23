#include "stdafx.h"
#include "Buffer.h"

Buffer::Buffer(int size) {
	this->size = size;
	this->count = 0;
}

Buffer::~Buffer() {}

Customer* Buffer::push(Customer* customer) {
	if (buff.size() == size) {
		return customer;
	}
	buff.append(customer);
	count++;
	return NULL;
}

Customer* Buffer::pop() {
	if (buff.isEmpty()) {
		return NULL;
	}

	unsigned short min(0xFFFF), index(0);
	int i;
	for (i=0; i<buff.size(); i++) {
		if (buff[i]->getSourceNo() < min) {
			min = buff[i]->getSourceNo();
			index = i;
		}
	}

	Customer* res = new Customer(buff.at(index)->getSourceNo(),buff.at(index)->getNo(), buff.at(index)->getArrivalTime());
	buff.remove(index);
	count--;
	return res;
}


bool Buffer::isEmpty()
{
	return buff.isEmpty();
}

void Buffer::print()
{
	for (int i = 0; i < size; i++)
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
	vector<string> res(size, "");
	for (int i = 0; i < size; i++)
	{
		if (i<count)
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





