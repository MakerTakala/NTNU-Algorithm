#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MAX_SIZE 105

int n, S, T, g_size;

int pre[MAX_SIZE];
vector<vector<int>> graph(MAX_SIZE, vector<int>(MAX_SIZE, 0));

int BFS() {
    memset(pre, -1, MAX_SIZE * sizeof(int));

    queue<int> q;
    pre[S] = 0;
    q.push(S);
    
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = 1; i < g_size; i++) {
            if(graph[u][i] > 0 && pre[i] == -1) {
                pre[i] = u;
                q.push(i);
            }
        }
    }

    return pre[T];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;

    S = 0; T = n + 1; g_size = n + 2;
    
    int sum = 0, x;

    for(int i = 0; i < n; i++) {
        cin>>x;
        graph[S][i + 1] = x;
    }
    for(int i = 0; i < n; i++) {
        cin>>x;
        graph[i + 1][T] = x;
        sum += x;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>x;
            if(x != 0) {
                graph[i + 1][j + 1] = x;
            }
        }
    }

    
    while(BFS() != -1) {
        int min_flow = INF;    
        int node = T;
        while(node != S) {
            int last = pre[node];
            min_flow = min(min_flow, graph[last][node]);
            node = last;
        }
        node = T;
        while(node != S) {
            int last = pre[node];
            graph[node][last] += min_flow;
            graph[last][node] -= min_flow;
            node = last;
        }
        sum -= min_flow;
    }

    cout<<sum<<endl;

    return 0;
}