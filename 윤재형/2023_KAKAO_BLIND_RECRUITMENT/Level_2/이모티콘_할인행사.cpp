#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> dc = {10, 20, 30, 40};
vector<int> comb_i(7, 0);
int emoji_size;

vector<vector<int>> g_users;
vector<int> g_emoticons;
vector<int> answer;

void comb(int index){
    if(index != emoji_size){
        for(int i = 0; i < 4; ++i){
            comb_i[index] = i;
            comb(index + 1);
        }
    }
    else{
        int service_user = 0;
        int emoji_cost = 0;
        
        for(int user = 0; user < g_users.size(); ++user){
            int cost = 0;
            for(int emoji = 0; emoji < emoji_size; ++emoji)
                if(g_users[user][0] <= dc[comb_i[emoji]])
                    cost += g_emoticons[emoji] * (100 - dc[comb_i[emoji]]) / 100;
            if(cost >= g_users[user][1]) ++service_user;
            else emoji_cost += cost;
        }
        
        if(answer.size() == 0){
            answer.push_back(service_user);
            answer.push_back(emoji_cost);
        }
        else if(answer[0] < service_user || (answer[0] == service_user && answer[1] < emoji_cost)){
            answer[0] = service_user;
            answer[1] = emoji_cost;
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    
    g_users = users;
    g_emoticons = emoticons;
    emoji_size = emoticons.size();
    
    comb(0);
    
    return answer;
}
