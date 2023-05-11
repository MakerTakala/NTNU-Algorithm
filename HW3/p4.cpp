#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    vector<int> pos(n + 1, -1);

    int size = -1;
    for(int i = 0, x, pre = INT_MAX; i < m; i++) {
        cin>>x;
        if(x < pre) {
            size++;
        }
        else {
        }
        pos[x] = size;
        pre = x;
    }
    
    if(size == 0) {
        cout<<2<<endl;
    }
    else {
        vector<int> visited(size + 1, 0);
        int ans = 1;
        for(int i = 1; i <= n; i++) {
            if(pos[i] == -1) continue;
            if(visited[pos[i]]) {
                ans++;
                fill(visited.begin(), visited.end(), 0);
                visited[pos[i]] = 1;
            }
            else {
                visited[pos[i]] = 1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}