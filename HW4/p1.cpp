#include <bits/stdc++.h>
using namespace std;

#define MAX 0x3ffffff

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<int>> graph(n, vector<int>(n, MAX));
    for(int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    unordered_map<string, int> hash;
    for(int i = 0, cur = 1; i < m; i++) {
        string city1, city2;
        cin>>city1>>city2;
        if(hash[city1] == 0) {
            hash[city1] = cur++;
        }
        if(hash[city2] == 0) {
            hash[city2] = cur++;
        }
        int len;
        cin>>len;
        graph[hash[city1] - 1][hash[city2] - 1] = min(len, graph[hash[city1] - 1][hash[city2] - 1]);
        graph[hash[city2] - 1][hash[city1] - 1] = min(len, graph[hash[city2] - 1][hash[city1] - 1]);
    }

    for(int p = 0; p < n; p++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][p] + graph[p][j]);
            }
        }
    }

    vector<int> move(k);
    for(int &x : move) {
        string name;
        cin>>name;
        x = hash[name];
    }

    int sum = 0;
    for(int i = 1; i < k; i++) {
        sum += graph[move[i - 1] - 1][move[i] - 1];
    }

    cout<<sum<<endl;

}