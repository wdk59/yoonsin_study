#include "이모티콘할인행사.h"

#include <string>
#include <vector>
#include <stack>

using namespace std;

void 이모티콘할인행사::진행()
{
    //이모티콘을 구매할 사람 (지불 용의가 있는 할인 비율, 지불 용의 금액)
    vector<vector<int>> users = { {40, 2900},{23, 10000},{11, 5200},{5, 5900}, {40, 3100},{27, 9200},{32, 6900} };

    //이모티콘의 가격 배열 
    vector<int> emoticaons = { 1300, 1500, 1600, 4900 };

    

    cout << "Solution: ";
    for (auto& i : solution(users, emoticaons))
    {
        cout << i << ", ";
    }
    cout << endl;
}

vector<int> 이모티콘할인행사::solution(vector<vector<int>> users, vector<int> emoticons) 
{
    vector<int> answer;
    vector<int> percentage(emoticons.size(), 0);

    int max_n_plus = 0;
    int max_cost = 0;
    int n_plus, cost, user_cost;
    for (int idx = 0; idx < (1 << (2 * emoticons.size())); idx++) {
        for (int i = 0; i < emoticons.size(); i++) {
            percentage[i] = (((idx >> (2 * i)) & 0x3) + 1) * 10;
        }
        n_plus = 0;
        cost = 0;
        for (auto& user_info : users) {
            user_cost = 0;

            for (int emo_idx = 0; emo_idx < emoticons.size(); emo_idx++) {
                if (user_info[0] <= percentage[emo_idx]) {
                    user_cost += emoticons[emo_idx] / 100 * (100 - percentage[emo_idx]);
                }
            }
            if (user_cost >= user_info[1]) {
                n_plus++;
            }
            else {
                cost += user_cost;
            }
        }
        if (max_n_plus < n_plus || (max_n_plus == n_plus && max_cost < cost)) {
            max_n_plus = n_plus;
            max_cost = cost;
        }
    }
    answer.push_back(max_n_plus);
    answer.push_back(max_cost);
    return answer;
}