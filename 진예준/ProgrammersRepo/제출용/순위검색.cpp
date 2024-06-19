#include <string>
#include <vector>
#include <map>
#include <sstream>

#define N_LANG 0
#define N_JOB 1
#define N_CAREER 2
#define N_FOOD 3
#define N_SCORE 4
#define Q_PASS "-"

using namespace std;

vector<int> solution(vector<string> info, vector<string> query)
{
	vector<int> answer;

	vector<string> devLang = { "cpp", "java", "python" };
	vector<string> devJob = { "backend, frontend" };
	vector<string> devCareer = { "junior", "senior" };
	vector<string> devFood = { "chicken", "pizza" };

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

	/*for (auto& ap : applicants)
	{
		for (auto& a : ap)
		{
			cout << a << "/";
		}
		cout << endl;
	}*/

	//쿼리문을 분석하고 쿼리를 실행
	for (auto& valueQuery : query)
	{
		istringstream str(valueQuery);
		string tempStr;
		vector<string> queryWords;

		int count = 0;

		while (getline(str, tempStr, ' '))
		{
			if (tempStr == "and") continue;
			queryWords.push_back(tempStr);
		}


		for (auto& applicant : applicants)
		{
			if (applicant[N_LANG] != queryWords[N_LANG] && queryWords[N_LANG] != Q_PASS)
			{
				continue;
			}
			if (applicant[N_JOB] != queryWords[N_JOB] && queryWords[N_JOB] != Q_PASS)
			{
				continue;
			}
			if (applicant[N_CAREER] != queryWords[N_CAREER] && queryWords[N_CAREER] != Q_PASS)
			{
				continue;
			}
			if (applicant[N_FOOD] != queryWords[N_FOOD] && queryWords[N_FOOD] != Q_PASS)
			{
				continue;
			}
			if (stoi(applicant[N_SCORE]) >= stoi(queryWords[N_SCORE]))
			{
				count++;
				/*cout << "App: ";
				for (auto& app : applicant)
				{
					cout <<app << " ";
				}
				cout << endl;

				cout << "QueryWoirds: ";
				for (auto& app : queryWords)
				{
					cout << app << " ";
				}
				cout << endl << endl;*/
			}

		}
		answer.push_back(count);
	}

	return answer;
}