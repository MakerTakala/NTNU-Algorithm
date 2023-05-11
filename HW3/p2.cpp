#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define MAXM 500005

struct cable {
    public:
        int u, v, w;

    cable(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }
    
    bool operator< (const cable &that) const{
        return w < that.w;
    };
};

int parent[MAXN] = {0};

int find_set(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find_set(parent[x]);
}

void union_set(int a, int b) {
    int pa = find_set(a), pb = find_set(b);
    if(pa != pb) parent[pa] = parent[pb];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    priority_queue<cable> pq;

    for(int i = 0, u, v, w; i < m; i++) {
       cin>>u>>v>>w;
       u--;
       v--;
       pq.push(cable(u, v, w));
    }

    vector<cable> pre_ans;

    for(int i = 0; i < n - 1;) {
        cable top = pq.top(); pq.pop();
        if(find_set(top.u) != find_set(top.v)) {
            union_set(top.u, top.v);
            i++;
        }
        pre_ans.push_back(top);
    }

    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int total = 0, having = 0;
    for(int i = pre_ans.size() - 1; i >= 0 && having < n - 1; i--) {
        if(find_set(pre_ans[i].u) != find_set(pre_ans[i].v)) {
            union_set(pre_ans[i].u, pre_ans[i].v);
            total += pre_ans[i].w;
            i++;
        }
    }

    cout<<total<<endl;


    return 0;
}