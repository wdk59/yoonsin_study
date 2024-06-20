#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<string>> v(4, vector<string>(2, "-"));
    map<string, vector<int>> m;
    
    for(int i = 0; i < info.size(); ++i){
        string s;
        istringstream ss(info[i]);
        
        int idx = 0, score = 0;
        while(ss >> s){
            if(idx < 4) v[idx++][0] = s;
            else score = stoi(s);
        }
        
        string a, b, c, d;
        for(int w = 0; w < 2; ++w){
            a = v[0][w];
            for(int x = 0; x < 2; ++x){
                b = v[1][x];
                for(int y = 0; y < 2; ++y){
                    c = v[2][y];
                    for(int z = 0; z < 2; ++z){
                        d = v[3][z];
                        m[a + b + c + d].push_back(score);
                    }
                }
            }
        }    
    }
    
    for(auto i : m) sort(m[i.first].begin(), m[i.first].end());
    
    for(string q : query){
        string s, tmp = "";
        int idx = 0, score = 0;
        
        istringstream ss(q);
        while(ss >> s){
            if(s == "and") continue;
            if(idx < 4){
                tmp += s;
                ++idx;
            }
            else score = stoi(s);
        }
        
        auto it = lower_bound(m[tmp].begin(), m[tmp].end(), score);
        answer.push_back(m[tmp].size() - (it - m[tmp].begin()));
    }
    
    return answer;
}
