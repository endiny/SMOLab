#include "stdafx.h"
#include "Buffer.h"

Buffer::Buffer(int size) {
	this->size = size;
	this->count = 0;
	buff = new BufferNode(true);
	size--;
	while (size) {
		buff->insert();
		size--;
	}
}

Buffer::~Buffer() {}

Customer* Buffer::push(Customer* customer) {
	for (int i=0; i<size; i++) {
		if (!(buff->getCustomer())) {
			buff->setCustomer(customer);
			buff = buff->next();
			return NULL;
		}
		buff = buff->next();
	}
	return customer;
}

Customer* Buffer::pop() {

	double min(1.7976931348623157e+308);
	int i;
	for (i=0; i<size; i++) {
		if (buff->getCustomer() && buff->getCustomer()->getArrivalTime() < min) {
			min = buff->getCustomer()->getArrivalTime();
			break;
		}
		buff = buff->next();
	}

	Customer* res = new Customer(buff->getCustomer()->getSourceNo(),
								 buff->getCustomer()->getNo(),
								 buff->getCustomer()->getArrivalTime());
	buff->setCustomer(NULL);
	buff = buff->next();
	return res;
}

void Buffer::print()
{
	for (int i = 0; i < size; i++)
	{
		if (buff->getCustomer() != NULL)
		{
			cout <<"    |"<< buff->getCustomer()->getSourceNo() << "-" << buff->getCustomer()->getArrivalTime() <<"|"<< endl;
		}
		else
		{
			cout << "    |NULL|" << endl;
		}
		buff = buff->next();
	}
}

bool Buffer::isEmpty()
{
	bool res = false;
	BufferNode* tmp = buff;
	for (int i=0; i<size; i++) {
		if (buff->getCustomer()) {
			return false;
		}
		tmp = tmp->next();
	}
	return true;
}

vector<string> Buffer::getBuffer()
{
	vector<string> res(size, "");
	for (int i = 0; i < size; i++)
	{
		if (buff->getCustomer())
		{
			res[i] += "Customer: " + to_string(buff->getCustomer()->getSourceNo()) + "-"+to_string(buff->getCustomer()->getNo());
		}
		else
		{
			res[i] += "-----";
		}
		buff = buff->next();
	}
	return res;
}





