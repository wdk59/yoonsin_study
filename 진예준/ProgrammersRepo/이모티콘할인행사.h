#pragma once
#include "Solution.h"

using namespace std;

class 이모티콘할인행사 : public Solution
{
public:
	virtual void 진행() override;
private:
	vector<int> solution(vector<vector<int>> users, vector<int> emoticons);
};