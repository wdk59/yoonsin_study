#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string comb_str;
map<string, int> m;

void comb(string s, int n, int r, int start){
    
    if(comb_str.size() == r){
        ++m[comb_str];
        return;
    }
    
    for(int i = start; i < n; ++i){
        comb_str.push_back(s[i]);
        comb(s, n, r, i + 1);
        comb_str.pop_back();
    }
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(auto len : course){
        for(auto order : orders){
            sort(order.begin(), order.end());
            comb(order, order.size(), len, 0);
        }
        
        int max_cnt = 0;
        for(auto menu : m)
            max_cnt = max(max_cnt, menu.second);
        
        for(auto menu : m){
            if(max_cnt < 2) break;
            else if(menu.second == max_cnt) answer.push_back(menu.first);
        }
        
        m.clear();
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
