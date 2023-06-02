#include <bits/stdc++.h>
using namespace std;

#define INF 0x3ffffff


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    vector<vector<pair<int, int>>> graph(n);
    
    for(int i = 0, a, b, w; i < m; i++) {
        cin>>a>>b>>w;
        graph[a - 1].push_back({w, b - 1});
        graph[b - 1].push_back({w, a - 1});
    }

    vector<tuple<int, int, int>> dis(n, {INF, 0, 0}); //{cost, max}
    vector<int> visited(n, 0);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, less<tuple<int, int, int>>> pq; //{w, node}
    pq.push({0,0, 0});
    get<0>(dis[0]) = 0;
    
    while(!pq.empty()) {
        auto top = pq.top(); pq.pop();
        int u = get<2>(top);
        if(visited[u] == 1) continue;

        
        for(auto [road_w, road_v] : graph[u]) {
            int node_cost = get<0>(dis[road_v]), node_vis = get<1>(dis[road_v]), node_max = get<2>(dis[road_v]);
            int new_cost = get<0>(dis[u]) + road_w, new_vis = get<1>(dis[u]) + 1, new_max = max(get<2>(dis[u]), road_w);
            
            if((node_cost - node_max > new_cost - new_max) || (node_cost - node_max == new_cost - new_max && new_vis < node_vis)) {
                dis[road_v] = {new_cost, new_vis, new_max};
                pq.push({new_cost - new_max, new_vis, road_v});
            }
        }


        visited[u] = 1;
        cout<<u<<": ";

        for(int i = 0 ; i < n; i++) {
            cout<<"{"<<get<0>(dis[i])<<", "<<get<1>(dis[i])<<", "<<get<2>(dis[i])<<"}";
        }
        cout<<endl;
    }

    cout<<get<0>(dis[n - 1]) - get<2>(dis[n - 1])<<" "<<get<1>(dis[n - 1]) - 1<<endl;

    return 0;
}