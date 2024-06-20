#include "택배배달과수거하기.h"
#include <string>
#include <vector>

using namespace std;

void 택배배달과수거하기::진행()
{
    //택배 용달차의 용량
    int cap = 4;

    //택배 배달할 가구의 수
    int n = 5;

    //물건을 배달해야하는 가구의 배열
    vector<int> deliveries = { 1, 0, 3, 1, 2 };

    //물건을 수거해야하는 가구의 배열
    vector<int> pickup = { 0, 3, 0, 4, 0 };
    std::cout << "Solution " << solution(cap, n, deliveries, pickup) << endl;
}

long long 택배배달과수거하기::solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    //출력할 답
    long long answer = 0;

    //이동한 거리가 답
    long long& distance = answer;

    const auto& truckCapacity = cap;
    
    int needDelivery = 0; //배달해야할 택배의 수
    int needPickup = 0; //수거해야할 택배의 수

    //현재 운반해야할 물건이 없으면
    for (int i = n - 1; i >= 0; i--)
    {
        auto& delivery = deliveries[i];
        auto& pickup = pickups[i];

        needDelivery += delivery;
        needPickup += pickup;

        while (needDelivery > 0 || needPickup > 0) 
        {
            needDelivery -= truckCapacity;
            needPickup -= truckCapacity;
            distance += (static_cast<long long>(i+1) * 2);
        }

    }

    return answer;
}