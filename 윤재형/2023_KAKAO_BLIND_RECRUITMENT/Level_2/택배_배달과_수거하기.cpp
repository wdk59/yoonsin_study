#include <string>
#include <vector>
#include <iostream>

using namespace std;

void start(int cap, vector<int> &arr, int idx){
    while(idx >= 0){
        if(cap >= arr[idx]){
            cap -= arr[idx];
            arr[idx--] = 0;
        }
        else{
            arr[idx] -= cap;
            break;
        }
    }
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    for(int i = n - 1; i >= 0;){
        if(deliveries[i] == 0 && pickups[i] == 0){
            --i;
            continue;
        }
        start(cap, deliveries, i);
        start(cap, pickups, i);
        answer += (i + 1) * 2;
    }
    
    return answer;
}
