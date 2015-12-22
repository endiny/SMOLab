#pragma once
class Poisson
{
private:
	float lambda;
	int k;
public:
	Poisson();
	~Poisson();

	int fact(int n);
	void setLambda(float mlambda);
	void reset();
	float next();
};

