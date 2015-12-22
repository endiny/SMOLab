#pragma once
class Generator
{
private:
	double intensity;

public:
	Generator(double intensity);
	double getNext();
	~Generator();
};

