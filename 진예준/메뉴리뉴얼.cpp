#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course)
{
	vector<string> answer;
	map<string, int> CourseSets;
	for (auto& order : orders)
	{
		sort(order.begin(), order.end());
		int n = order.length();
		int totalCombinationNumber = 1 << n;

		//비트마스크를 통해 조합구하기
		for (int bitmask = 0; bitmask < totalCombinationNumber; bitmask++)
		{
			vector<int> combination;
			for (int i = 0; i < order.length(); i++)
			{
				if (bitmask & (1 << i))
				{

					combination.push_back(order[i]);
				}
			}
			if (find(course.begin(), course.end(), combination.size()) != course.end())
			{
				string str(combination.begin(), combination.end());
				int count = CourseSets[str];
				CourseSets[str]++;
			}

		}


	}

	//코스 가짓수마다 하나씩 골라야 하니까
	for (auto& cosType : course)
	{
		int max = 0;
		vector<string> MaxCourse;



		//집합중에서 코스에 들어갈 것 선정
		for (auto& value : CourseSets)
		{
			if (value.second < 2) continue;
			if (value.first.length() != cosType) continue; //코스타입이랑 안맞으면 안되니까.
			if (value.second > max)
			{
				MaxCourse.clear();
				MaxCourse.push_back(value.first);
				max = value.second;
			}
			else if (value.second == max)
			{
				MaxCourse.push_back(value.first);
			}
		}

		answer.insert(answer.end(), MaxCourse.begin(), MaxCourse.end());
		MaxCourse.clear();
	}

	sort(answer.begin(), answer.end());



	return answer;
}