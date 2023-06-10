#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MAX_SIZE 205

int n, S, T, g_size;

vector<int> pre(MAX_SIZE);
vector<int> flow(MAX_SIZE, 0);

int BFS(vector<vector<int>> &graph) {
    fill(pre.begin(), pre.begin() + g_size, -1);
    fill(flow.begin(), flow.begin() + g_size, 0);
    queue<int> q;
    flow[S] = INF;
    pre[S] = 0;
    q.push(S);
    
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u == T) break;
        for(int i = 1; i < g_size; i++) {
            if(graph[u][i] > 0 && pre[i] == -1) {
                pre[i] = u;
                flow[i] = min(flow[u], graph[u][i]);
                q.push(i);
            }
        }
    }

    if(pre[T] == -1) return -1;
    return flow[T];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;

    S = 0; T = 2 * n + 1; g_size = 2 * n + 2;

    vector<vector<int>> graph(g_size, vector<int> (g_size, 0));
    
    int sum = 0, x;

    for(int i = 0; i < n; i++) {
        cin>>x;
        graph[S][i + 1] = x;
        graph[i + 1][n + 1 + i] = x;
    }
    for(int i = 0; i < n; i++) {
        cin>>x;
        graph[n + 1 + i][T] = x;
        sum += x;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>x;
            if(x != 0) {
                graph[i + 1][n + 1 + j] = x;
            }
        }
    }

    int add_flow = 0;
    while(add_flow = BFS(graph) != -1) {
        int node = T;
        while(node != S) {
            int last = pre[node];
            graph[node][last] += add_flow;
            graph[last][node] -= add_flow;
            node = last;
        }
        sum -= add_flow;
    }

    cout<<sum<<endl;

    return 0;
}