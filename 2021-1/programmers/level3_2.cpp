#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int N, vector<int> works) {
    long long answer = 0;
    priority_queue<long long> pq;
    for (auto it = works.begin(); it != works.end(); it++) {
        pq.push(*it);
    }
    for (int n = 0; n < N; n++)  {
        long long tmp = pq.top();
        if (tmp == 0) {
            break;
        }
        pq.pop();
        pq.push(tmp - 1);
    }
    while(!pq.empty()){
        long long tmp = pq.top();
        pq.pop();      
        answer += tmp * tmp;  
    }
    
    return answer;
}