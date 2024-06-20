#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct information {
    string lang = "";
    string job = "";
    string career = "";
    string food = "";
    int score = 0;
};

map<string, vector<int>> table; //query에서 요구하는 조건에 해당하는 인원의 코딩테스트 점수 리스트 

void make_table(string lang, string job, string career, string food, int score) {
    string key = lang + job + career + food;
    table[key].push_back(score);
}

vector<int> solution(vector<string> info, vector<string> query) {


    vector<information> v;
    vector<int> answer;
    for (int i = 0; i < info.size(); i++) {
        string str = info[i];
        information in;

        //문자열 분해
        int pos = 0;
        int cnt = 0;
        string delimiter = " ";
        while ((pos = str.find(delimiter)) != string::npos) {

            string token = str.substr(0, pos);
            if (cnt == 0) in.lang = token;
            else if (cnt == 1) in.job = token;
            else if (cnt == 2) in.career = token;
            else if (cnt == 3) in.food = token;

            cnt++;
            str.erase(0, pos + delimiter.length());
        }
        //cout << str << '\n';
        in.score = stoi(str);

        //키 생성 후 테이블에 저장
        string all_tag = "-";
        make_table(in.lang, in.job, in.career, in.food, in.score);

        make_table(in.lang, in.job, in.career, all_tag, in.score);
        make_table(in.lang, in.job, all_tag, in.food, in.score);
        make_table(in.lang, all_tag, in.career, in.food, in.score);
        make_table(all_tag, in.job, in.career, in.food, in.score);

        make_table(in.lang, in.job, all_tag, all_tag, in.score);
        make_table(in.lang, all_tag, all_tag, in.food, in.score);
        make_table(all_tag, all_tag, in.career, in.food, in.score);
        make_table(all_tag, in.job, in.career, all_tag, in.score);
        make_table(all_tag, in.job, all_tag, in.food, in.score);
        make_table(in.lang, all_tag, in.career, all_tag, in.score);


        make_table(in.lang, all_tag, all_tag, all_tag, in.score);
        make_table(all_tag, in.job, all_tag, all_tag, in.score);
        make_table(all_tag, all_tag, all_tag, in.food, in.score);
        make_table(all_tag, all_tag, in.career, all_tag, in.score);

        make_table(all_tag, all_tag, all_tag, all_tag, in.score);


        v.push_back(in);
    }

    //테이블 오름차순으로 정렬
    //for (auto p : table) {
    //    sort(p.second.begin(), p.second.end());
    //    cout << "key : " << p.first;
    //    for (int i = 0; i < p.second.size(); i++) {
    //        cout << p.second[i] << ' ';
    //    }

    //    cout << '\n';
    //}

    for (auto i = table.begin(); i != table.end(); i++) {
        sort(i->second.begin(), i->second.end());
    }


    for (int i = 0; i < query.size(); i++) {
        string str = query[i];
        information target_info;
        int ret = 0;

        //문자열 분해
        int pos = 0;
        int cnt = 0;
        string delimiter = " and ";
        while ((pos = str.find(delimiter)) != string::npos) {

            string token = str.substr(0, pos);
            if (cnt == 0) target_info.lang = token;
            else if (cnt == 1) target_info.job = token;
            else if (cnt == 2) target_info.career = token;
            else if (cnt == 3) target_info.food = token;

            cnt++;
            str.erase(0, pos + delimiter.length());
            if (cnt == 3) delimiter = " ";
        }
        //cout << str << '\n';
        target_info.score = stoi(str);


        string key = target_info.lang + target_info.job + target_info.career + target_info.food;
        //cout << "query\n";
        //cout << "key : " << key;
        //for (int i = 0; i < table[key].size(); i++) {
        //    cout << table[key][i] << ' ';
        //}

        //cout << '\n';


        if (table[key].size() == 0) {
            ret = 0;
        }
        else {
            auto value = lower_bound(table[key].begin(), table[key].end(), target_info.score);
            if (value == table[key].end()) {
                ret = 0;
            }
            else {
                ret = table[key].size() - (value - table[key].begin());
            }
        }

        answer.push_back(ret);
    }



    return answer;
}
