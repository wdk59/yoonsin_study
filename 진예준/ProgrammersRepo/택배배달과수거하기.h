#pragma once
#include "Solution.h"

using namespace std;

class 택배배달과수거하기 : public Solution
{
public:
	virtual void 진행() override;
private:
	long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups);
};

