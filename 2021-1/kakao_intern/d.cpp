#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define FOR(i, j) for (int i = 0; i < j; i++)
#define INF 1987654321

bool isTrap[11] = {0};
int N;
vector<vector<int> > distList;
int dist[1001];

void trapped(int trapHere, vector<pair<int,int> > edge[1001], int curDist[1001], vector<int> trapList) {
    int tl[1001] = {0};
    tl[trapHere] = 1;
    FOR(t, trapList.size()) {
        if (tl[t] == 3) return;
        else tl[t]++;
    }
    trapList.push_back(trapHere);
    vector<pair<int,int> > copyEdge[1001];
    vector<pair<int,int> > tmp[1001];
    FOR(i, N + 1) {
        FOR(j, edge[i].size()) {
            if (i == trapHere) {
                tmp[edge[i][j].first].push_back({i, edge[i][j].second});
            } else {
                copyEdge[i].push_back(edge[i][j]);
            }
        }
    }
    
    FOR(i, N + 1) {
        for(auto it = copyEdge[i].begin(); it != copyEdge[i].end();) {
            if (it->first == trapHere) {
                tmp[trapHere].push_back({i, it->second});
                it = copyEdge[i].erase(it);
            } else {
                it++;
            }
        }
    }
    
    FOR(i, N + 1) {
        FOR(j, tmp[i].size()) {
            copyEdge[i].push_back(tmp[i][j]);
        }
    }
    
    int copyDist[1001];
    fill(copyDist, copyDist + N + 1, INF);
    copyDist[trapHere] = curDist[trapHere];
    // FOR(i, N + 1) {
    //     cout << i << '\n';
    //     FOR(j, tmp[i].size()) {
    //         cout << tmp[i][j].first << " " << tmp[i][j].second << '\n';
    //     }
    // }
    
    priority_queue<pair<int,int> > qu;     
    
    for(int i = 0; i < copyEdge[trapHere].size(); i++) {
        int next = copyEdge[trapHere][i].first;
        int nextcost = copyEdge[trapHere][i].second;
        if (copyDist[next] > copyDist[trapHere] + nextcost) { 
            copyDist[next] = copyDist[trapHere] + nextcost;
            if (dist[next] > copyDist[next]) {
                dist[next] = copyDist[next];
            }
            qu.push({-copyDist[next], next});
        }
    }
    
    // FOR(i, N + 1) {
    //     cout << i << '\n';
    //     FOR(j, copyEdge[i].size()) {
    //         cout << copyEdge[i][j].first << " " << copyEdge[i][j].second << '\n';
    //     }
    // }
    // cout << trapHere << "===================\n";
    
    while(!qu.empty()){
        int cost = -qu.top().first;
        int here = qu.top().second;
        
        qu.pop();
            
        if (isTrap[here]) {
            trapped(here, copyEdge, copyDist, trapList);
            continue;
        }
        for(int i = 0; i < copyEdge[here].size(); i++) {
            int next = copyEdge[here][i].first;
            int nextcost = copyEdge[here][i].second;
            if (copyDist[next] > copyDist[here] + nextcost) { 
                copyDist[next] = copyDist[here] + nextcost;
                qu.push({-copyDist[next], next});
            }
        }
    }
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    N = n;
    
    FOR(trap, traps.size()) {
        isTrap[traps[trap]] = true;
    }
    
    vector<pair<int,int> > edge[1001];
    for(int i = 0; i < roads.size(); i++){
        edge[roads[i][0]].push_back({roads[i][1], roads[i][2]});
    }
    
    fill(dist, dist + n + 1, INF);
    priority_queue<pair<int,int> > qu;     
    
    qu.push({0, start}); 
    dist[start] = 0;
    
    while(!qu.empty()){
        int cost = -qu.top().first;
        int here = qu.top().second;
        
        qu.pop();
            
        if (isTrap[here]) {
            vector<int> empt;
            trapped(here, edge, dist, empt);
            continue;
        }
        for(int i = 0; i < edge[here].size(); i++) {
            int next = edge[here][i].first;
            int nextcost = edge[here][i].second;
            if (dist[next] > dist[here] + nextcost) { 
                dist[next] = dist[here] + nextcost;
                qu.push({-dist[next], next});
            }
        }
        
    }
     // cout << dist[end] << '\n';
    answer= dist[end];
    return answer;
}