#include "stdafx.h"
#include "Buffer.h"

Buffer::Buffer(int size):
	m_size(size)
{
	this->m_size = size;
	this->count = 0;
	buff = QVector<Customer*>(size, NULL);
}

Buffer::~Buffer() {}

Customer* Buffer::push(Customer* customer) {
	count++;
	for (int i=0; i < this->m_size; i++)
	{
		if (!buff[i]) {
			buff[i] = customer;
			return NULL;
		}
	}
	return customer;
}

Customer* Buffer::pop() {
	if (this->isEmpty()) {
		return NULL;
	}
	uint minSourceNo(0xFFFFFFFF);
	double minTime(INFINITY);
	uint res(0xFFFFFFFF);
	for (uint i=0; i < this->m_size; i++) {
		if (buff[i] && buff[i]->getSourceNo() < minSourceNo) minSourceNo = buff[i]->getSourceNo();
	}
	for (uint i=0; i < this->m_size; i++) {
		if (buff[i] && buff[i]->getArrivalTime() < minTime) {
			minTime = buff[i]->getArrivalTime();
			res = i;
		}
	}
	Customer* result = new Customer(buff[res]->getSourceNo(), buff[res]->getNo(), buff[res]->getArrivalTime());
	delete buff[res];
	buff[res]=NULL;
	return result;
}


bool Buffer::isEmpty()
{
	foreach (auto i, buff) {
		if (i) return false;
	}
	return true;
}

void Buffer::print()
{
	for (int i = 0; i < m_size; i++)
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
	vector<string> res(m_size, "");
	for (int i = 0; i < m_size; i++)
	{
		if (buff[i]) {
			if (i<count)
			{
				res[i] += "Customer: " + to_string(buff[i]->getSourceNo()) + "-"+to_string(buff[i]->getNo());
			}
			else
			{
				res[i] += "-----";
			}
		}
	}
	return res;
}
