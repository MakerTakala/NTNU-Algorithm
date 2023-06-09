#include <bits/stdc++.h>
using namespace std;

#define INF 0x3ffffff

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    vector<vector<pair<long long int, int>>> graph(2 * n);

    for(int i = 0, u, v, w; i < m; i++) {
        cin>>u>>v>>w;
        u--; v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        graph[u + n].push_back({v + n, w});
        graph[v + n].push_back({u + n, w});
        graph[u].push_back({v + n, 0});
        graph[v].push_back({u + n, 0});
    }

    vector<long long int> dis(2 * n, INF);
    vector<int> count(2 * n, 0);
    vector<int> visited(2 * n, 0);

    dis[0] = 0;

    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
    pq.push({dis[0], 0});

    while(!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if(visited[u] == 1) continue;

        for(auto [v, w] : graph[u]) {
            if(dis[u] + w < dis[v] || (dis[u] + w == dis[v] && count[u] + 1 > count[v])) {
                dis[v] = dis[u] + w;
                count[v] = count[u] + 1;
                pq.push({dis[v], v});
            }
        }
        visited[u] = 1;
    }

    cout<<dis[2 * n - 1]<<" "<<count[2 * n - 1] - 1<<endl;    
  
    return 0;
}