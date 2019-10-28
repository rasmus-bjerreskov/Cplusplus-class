#pragma once
class Inspector
{
private:
	float lower;
	float upper;

public:
	void setLimits(float l_bound, float u_bound);
	bool isInLimits(float test);
};

