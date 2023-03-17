#include <bits/stdc++.h>
using namespace std;

void forward(vector<int> &diff, int &cur_pos, int &cur_sum) {
    while(cur_pos < diff.size() && cur_sum + diff[cur_pos] <= 0) {
        cur_sum += diff[cur_pos];
        cur_pos++;
    }
}

int slover(vector<int> &diff, int n, int m) {
    int u, v, k;
    int cur_pos = 0, cur_sum = 0;

    forward(diff, cur_pos, cur_sum);
    if(cur_pos == n) return 0;

    for(int i = 1 ; i <= m; i++) {
        cin>>u>>v>>k;

        if(v + 1 < cur_pos) continue;
        if(u < cur_pos && cur_pos <= v + 1) u = cur_pos;

        diff[u] -= k;
        if(v < n) diff[v + 1] += k;

        forward(diff, cur_pos, cur_sum);
        if(cur_pos == n) return i;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    vector<int> areas(n, 0);
    vector<int> diff(n, 0);

    for(int &area : areas) {
        cin>>area;
    }

    diff[0] = areas[0];
    for(int i = 1; i < n; i++) {
        diff[i] = areas[i] - areas[i - 1];
    }

    cout<<slover(diff, n, m)<<endl;
    return 0;
}