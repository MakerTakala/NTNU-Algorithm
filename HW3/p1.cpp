#include <bits/stdc++.h>
using namespace std;

#define MAX 1000005

int idx = 0;
vector<int> dfn(MAX, 0), low(MAX, 0);
vector<vector<int>> graph(MAX);
vector<pair<int, int>> ans;

void DFS(int cur, int parent) {
    dfn[cur] = low[cur] = ++idx;
    
    for(int next : graph[cur]) {
        if(dfn[next] == 0) {
            DFS(next, cur);
            low[cur] = min(low[cur], low[next]);

            if(low[next] > dfn[cur]) {
                ans.push_back({min(cur, next), max(cur, next)});
            }
        }
        else if(next != parent) {
            low[cur] = min(low[cur], dfn[next]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    
    for(int i = 0, a, b; i < m; i++) {
        cin>>a>>b;
        if(a == b) continue;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        if(dfn[i] == 0) {
            DFS(i, -1);
        }
    }

    sort(ans.begin(), ans.end());

    if(ans.empty()) cout<<"No Critical Road"<<endl;
    for(auto x : ans) {
        cout<<x.first<<" "<<x.second<<endl;
    }

    return 0;
}