#pragma once
#include "Solution.h"
using namespace std;

class 순위검색 : public Solution
{
public:
	virtual void 진행() override;
private:
	vector<int> solution(vector<string> info, vector<string> query);
};

