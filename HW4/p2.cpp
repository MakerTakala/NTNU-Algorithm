#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    vector<vector<pair<double, int>>> graph(n);
    for(int i = 0, a, b; i < m; i++) {
        long double w;
        cin>>a>>b>>w;
        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }
    

    int start, end;
    cin>>start>>end;

    vector<double> prob(n, 0);
    vector<int> visited(n, 0);
    priority_queue<pair<double, int>> pq;
    pq.push({1, start});
    prob[start] = 1;
    

    while(!pq.empty()) {
        auto top = pq.top(); pq.pop();
        if(visited[top.second] == 1) continue;

        for(auto node : graph[top.second]) {
            if(prob[node.second] < prob[top.second] * node.first) {
                prob[node.second] = prob[top.second] * node.first;
                pq.push({prob[node.second], node.second});
            }
        }
        visited[top.second] = 1;
    }
    cout<<fixed<<setprecision(3)<<prob[end]<<endl;



    return 0;
}