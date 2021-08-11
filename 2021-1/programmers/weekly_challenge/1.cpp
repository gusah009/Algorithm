using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long change = money;
    
    FOR(cnt, count) {
        change -= price * (cnt + 1);
    }
    answer = change > 0 ? 0 : -change;
    return answer;
}