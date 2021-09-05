#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include<cassert>

#define FOR(i, j) for(int i = 0; i < j; i++)

using namespace std;

bool isEatComplete[200010] = {0};

int solution(vector<int> food_times, long long k) {
    int answer = -1;
    
    vector<pair<int, int> > food_times_sorted;
    food_times_sorted.resize(food_times.size());
    
    FOR(i, food_times.size()) {
        food_times_sorted[i] = pair<int, int>(food_times[i], i);
    }
    sort(food_times_sorted.begin(), food_times_sorted.end());
    
    long long prev_food_times = 0;
    long long remain_food = food_times.size();
    
    FOR(i, food_times_sorted.size()) {
        if (prev_food_times == food_times_sorted[i].first) {
            isEatComplete[food_times_sorted[i].second] = true;
            remain_food--;
            continue;
        }
        
        long long take_time = (food_times_sorted[i].first - prev_food_times) * remain_food;
        if (take_time <= k) {
            k -= take_time;
        } else {
            break;
        }
            
        prev_food_times = food_times_sorted[i].first;
        isEatComplete[food_times_sorted[i].second] = true;
        remain_food--;
    }
    if (remain_food != 0) k %= remain_food;
    else return -1;
    
    FOR(i, food_times.size()) {
        if (!isEatComplete[i]) {
            k--;
        }
        if (k == -1) {
            answer = i;
            break;
        }
    }
    return (answer + 1);
}