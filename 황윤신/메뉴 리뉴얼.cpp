#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <iostream>

using namespace std;

struct info {
    int num = 0; //코스 조합이 나온 횟수
    vector<string> list; //코스 조합 리스트
};

//조합 만들기
void combination(string& str, map<int, info>& table, map<string, int>& table_2, bool is_course[], string temp, int start, int size, int& max_size) {

    if (is_course[size]) {

        //cout << "size : " << size << " 완성된 문자열 :" << temp << '\n';
        //코스 숫자에 맞는 조합 하나 완성
        table_2[temp]++;
        if (table[size].num < table_2[temp]) {

            table[size].num = table_2[temp];
            if (table[size].list.size() >= 1) table[size].list.clear();
            table[size].list.push_back(temp);
        }
        else if (table[size].num == table_2[temp]) {
            table[size].list.push_back(temp);
        }


        if (size == max_size) {
            //cout << "max_size :" << max_size << '\n';
            return;
        }
    }

    for (int i = start; i < str.length(); i++) {
        temp += str[i];
        combination(str, table, table_2, is_course, temp, i + 1, size + 1, max_size);
        temp.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {

    //스카피가 추가하고 싶어하는 코스요리 목록
    map<int, info> table;
    //나온 횟수
    map<string, int> table_2;

    int max_size = 0;
    bool is_course[11];
    memset(is_course, 0, sizeof(bool) * 11);
    for (int i = 0; i < course.size(); i++) {
        is_course[course[i]] = true;
        max_size = max(max_size, course[i]);
    }


    //문자열 정렬
    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }

    for (int i = 0; i < orders.size(); i++) {
        string target = orders[i];
        for (int j = i + 1; j < orders.size(); j++) {
            string compare = orders[j];
            string str = "";

            //중복되는 문자열 얻기
            for (int k = 0; k < target.size(); k++) {
                for (int x = 0; x < compare.size(); x++) {
                    if (target[k] == compare[x]) {
                        str += target[k];
                    }
                }
            }

            //cout << "중복되는 문자열 : " << str << '\n';
             //같은 문자 조합을 찾기
            combination(str, table, table_2, is_course, "", 0, 0, max_size);
        }
    }


    vector<string> answer;
    for (auto p : table) {
        for (int i = 0; i < p.second.list.size(); i++) answer.push_back(p.second.list[i]);
    }
    sort(answer.begin(), answer.end());




    return answer;
}