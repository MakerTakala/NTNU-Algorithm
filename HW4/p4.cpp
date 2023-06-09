#include <bits/stdc++.h>
using namespace std;

int S, T, g_size;

vector<long long int> BFS(vector<vector<pair<int, long long int>>> &graph) {
    vector<int> visited(g_size, 0);
    queue<vector<long long int>> q;
    q.push(vector<long long int>{0});

    while(!q.empty()) {
        vector<long long int> top = q.front(); q.pop();
        int u = top.back();
        visited[u] = 1;
        for(auto [v, w] : graph[u]) {
            if(visited[v] == 1) continue;
            top.push_back(v);
            if(v == T) return top;
            q.push(top);
            top.pop_back();
        }
    }
    return vector<long long int>();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    S = 0; T = 2 * n + 1; g_size = 2 * n + 2;
    vector<vector<pair<int, long long int>>> graph(g_size);
    
    long long int sum = 0, x;

    for(int i = 0; i < n; i++) {
        cin>>x;
        graph[S].push_back({i + 1, x});
    }
    for(int i = 0; i < n; i++) {
        cin>>x;
        sum += x;
        graph[n + 1 + i].push_back({T, x});
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>x;
            if(x == 0) continue;
            graph[i + 1].push_back({n + 1 + j, x});   
        }
        cout<<i;
        cout<<"OK"<<endl;
    }
    for(int i = 0; i < n; i++) {
        graph[i + 1].push_back({n + 1 + i, LLONG_MAX});
    }


    while(1) {
        vector<long long int> argu_road = BFS(graph);
        
        if(argu_road.size() == 0) break;
        
        long long int max_flow = LLONG_MAX;
        for(int i = 0; i < argu_road.size() - 1; i++) {
            auto it = find_if(graph[argu_road[i]].begin(), graph[argu_road[i]].end(), [&](pair<int, long long int> value) { return value.first == argu_road[i + 1]; });
            max_flow = min(max_flow, it->second);
        }

        sum -= max_flow;

        for(int i = 0; i < argu_road.size() - 1; i++) {
            auto it1 = find_if(graph[argu_road[i]].begin(), graph[argu_road[i]].end(), [&](pair<int, long long int> value) { return value.first == argu_road[i + 1]; });
            it1->second -= max_flow;

            auto it2 = find_if(graph[argu_road[i + 1]].begin(), graph[argu_road[i + 1]].end(), [&](pair<int, long long int> value) { return value.first == argu_road[i]; });
            if(it2 == graph[argu_road[i + 1]].end()) {
                graph[argu_road[i + 1]].push_back({argu_road[i], max_flow});
            }
            else {
                it2->second += max_flow;
            }
        }
    }

    cout<<sum<<endl;

    return 0;
}