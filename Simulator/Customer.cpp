#include "stdafx.h"
#include "Customer.h"
#include <qdebug.h>


Customer::Customer(int sourceNo, int No, double arrivalTime)
{
	this->arrivalTime = arrivalTime;
	//TODO: Some bug is here. Or somewhere else!
	this->sourceNo = sourceNo;
    this->No = No;
	serverNo = -1;
	//  a = 0.0f;
}


Customer::~Customer()
{
}

double Customer::getArrivalTime() {
	return arrivalTime;
}

int Customer::getSourceNo()
{
	return sourceNo;
}

int Customer::getNo()
{
	return No;
}

void Customer::setBufferTime(double bufferTime)
{
	this->bufferTime = bufferTime;
}

double Customer::getBufferTime()
{
	return bufferTime;
}

void Customer::setServiceTime(double st)
{
	serviceTime = st;
}

double Customer::getServiceTime()
{
	return serviceTime;
}

void Customer::setServerNo(int serverNo)
{
	this->serverNo = serverNo;
}

int Customer::gerServerNo()
{
	return serverNo;
}

