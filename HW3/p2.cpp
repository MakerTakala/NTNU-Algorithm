#include <bits/stdc++.h>
using namespace std;

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    vector<vector<cable>> cables(n);

    for(int i = 0, u, v, w; i < m; i++) {
       cin>>u>>v>>w;
       u--;
       v--;
       cables[u].push_back(cable(u, v, w));
       cables[v].push_back(cable(v, u, w));
    }

    
    for(int i = 0; i < n; i++) {
        cout<<i<<": "<<endl;
        for(auto cab : cables[i]) {
            cout<<"    "<<cab.u<<" "<<cab.v<<" "<<cab.w<<endl;
        }
        cout<<endl;
    }

    priority_queue<cable> pq;

    int cur = 0, line = 0, total = 0;
    vector<int> visited(n, 0);
    
    for(int i = 0; i < n - 1; i++) {
        cout<<cur<<endl;
        visited[cur] = 1;
        for(auto next : cables[cur]) {
            pq.push(next);
        }
        while(1) {
            cable top = pq.top(); pq.pop();
            if(!visited[top.v]) {
                total += top.w;
                cur = top.v;
                break;
            }
        }
    }


    cout<<total<<endl;


    return 0;
}