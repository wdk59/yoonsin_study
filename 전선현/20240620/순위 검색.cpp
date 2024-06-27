// https://wadekang.tistory.com/15
// 맵, 비트마스크를 사용

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> data_parse(string data) {
    vector<string> ret;
    string tmp = "";

    for (auto c : data) {
        if (c == ' ') {
            if (tmp != "and") ret.push_back(tmp);
            tmp = "";
        }
        else tmp += c;
    }

    ret.push_back(tmp);
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    // key: 언어직군경력소울프드, value: 코딩테스트점수
    unordered_map<string, vector<int>> db;
    for (auto inf : info) {
        vector<string> key = data_parse(inf);

        for (int i = 0; i < 16; ++i) {
            string tmp = "";
            for (int j = 0; j < 4; ++j) {
                tmp += (i & (1 << j)) ? key[j] : "-";
            }
            db[tmp].push_back(stoi(key[4]));
        }
    }

    // lower_bound 사용 위해 sort
    for (auto& iter : db) sort(iter.second.begin(), iter.second.end());

    for (auto q : query) {
        vector<string> key = data_parse(q);

        string k = key[0] + key[1] + key[2] + key[3];
        vector<int> res = db[k];

        // 이진탐색으로 기준 점수 이하인 케이스를 전체 케이스 수에서 뺀 결과를 저장
        int cnt = res.end() - lower_bound(res.begin(), res.end(), stoi(key[4]));
        answer.push_back(cnt);
    }

    return answer;
}