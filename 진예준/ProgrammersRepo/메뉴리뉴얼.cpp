#include "메뉴리뉴얼.h"
#include <map>
#include <algorithm>

void 메뉴리뉴얼::진행()
{
	vector<string> orders = { "XYZ", "XWY", "WXA" };
	vector<int> course = { 2, 3, 4 };


	// Case 2: ["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"], [2, 3, 5]
	// Case 3: ["XYZ", "XWY", "WXA"], [2, 3, 4]

	for (auto& answer : solution(orders, course))
	{
		cout << "[" << answer << "] ";
	}
}

vector<string> 메뉴리뉴얼::solution(vector<string> orders, vector<int> course)
{
	vector<string> answer;
	map<string, int> CourseSets;
	for (auto& order : orders)
	{
		sort(order.begin(), order.end()); //안하면 Case 3가 되지 않음.
		int n = order.length();  
		int totalCombinationNumber = 1 << n;
		
		//비트마스크를 통해 조합구하기
		for (int bitmask = 0; bitmask < totalCombinationNumber; bitmask++)
		{
			vector<int> combination;
			for (int i = 0; i < order.length(); i++) //r 부분
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
	
	for (auto& value : CourseSets)
	{
		cout << "{" << value.first << ", " << value.second << "} ";
	}
	cout << endl;

	//코스 가짓수마다 하나씩 골라야 하니까
	for (auto& cosType : course)
	{
		int max = 0;
		vector<string> MaxCourse;

		

		//집합중에서 코스에 들어갈 것 선정
		for (auto& value : CourseSets)
		{
			if (value.second < 2) continue; //안하면 Case 2가 되지 않음.
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