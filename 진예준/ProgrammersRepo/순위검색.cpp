#include "순위검색.h"

void 순위검색::진행()
{
	vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150",
		"cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
	vector<string> query = { "java and backend and junior and pizza 100",
		"python and frontend and senior and chicken 200","cpp and - and senior and pizza 250",
		"- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"
	};

	cout << "[";
	for (auto& value : solution(info, query))
	{
		cout << value << ", ";
	}
	cout <<"]";

	//info
	//["java backend junior pizza 150",
	// "python frontend senior chicken 210","python frontend senior chicken 150",
	// "cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]

	// query
	//["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250",
	// "- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]
}

#include <map>
#include <sstream>

#define N_LANG 0
#define N_JOB 1
#define N_CAREER 2
#define N_FOOD 3
#define N_SCORE 4
#define Q_PASS "-"

vector<int> 순위검색::solution(vector<string> info, vector<string> query) 
{
	vector<int> answer;
	vector<vector<string>> applicants;

	//참가자를 분석
	for (auto& valueInfo : info)
	{
		istringstream str(valueInfo);
		string tempStr;
		vector<string> applicant;

		while (getline(str, tempStr, ' '))
		{
			applicant.push_back(tempStr);
		}
		applicants.push_back(applicant);
	}

	//쿼리문을 분석하고 쿼리를 실행
	for (auto& valueQuery : query)
	{
		istringstream str(valueQuery);
		string tempStr;
		vector<string> queryWords;

		int count=0;

		while (getline(str, tempStr, ' '))
		{
			if (tempStr == "and") continue;
			queryWords.push_back(tempStr);
		}


		for (auto& applicant : applicants)
		{
			if (queryWords[N_LANG] != Q_PASS && applicant[N_LANG] != queryWords[N_LANG])
			{
				continue;
			}
			if (queryWords[N_JOB] != Q_PASS && applicant[N_JOB] != queryWords[N_JOB])
			{
				continue;
			}
			if (queryWords[N_CAREER] != Q_PASS && applicant[N_CAREER] != queryWords[N_CAREER])
			{
				continue;
			}
			if (queryWords[N_FOOD] != Q_PASS && applicant[N_FOOD] != queryWords[N_FOOD])
			{
				continue;
			}
			if (stoi(applicant[N_SCORE]) >= stoi(queryWords[N_SCORE]))
			{
				count++;
			}
			
		}
		answer.push_back(count);
	}

	return answer;
}