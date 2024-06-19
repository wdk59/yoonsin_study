#pragma once
#include "Solution.h"

using namespace std;

class 메뉴리뉴얼 : public Solution
{
public:
	virtual void 진행() override;
private:
	vector<string> solution(vector<string> orders, vector<int> course);
};

