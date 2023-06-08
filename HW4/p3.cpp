#include <bits/stdc++.h>
using namespace std;

#define INF 0x3ffffff

class Road {
    public:
        int from, to, w;

        Road(int _from, int _to, int _w) {
            from = _from;
            to = _to;
            w = _w;
        }
};

class Node {
    public:
        int from, dis, max_road, visit;

        Node() {
            dis = INF;
            max_road = 0;
            visit = 0;
        }

        bool operator< (const Node &that) const {
            if(dis == that.dis && max_road == that.max_road) return visit < that.visit;
            if(dis == that.dis) return max_road < that.max_road;
            return dis > that.dis;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    vector<vector<Road>> graph(n);

    for(int i = 0, u, v, w; i < m; i++) {
        cin>>u>>v>>w;
        graph[u - 1].push_back(Road(u - 1, v - 1, w));
        graph[v - 1].push_back(Road(v - 1, u - 1, w));
    }

    

    vector<Node> cost(n);
    cost[0].dis = 0;
    for(int i = 0; i < n; i++) {
        cost[i].from = i;
    }

    priority_queue<Node> pq;
    pq.push(cost[0]);

    vector<int> visited(n, 0);

    while(!pq.empty()) {
        Node top = pq.top(); pq.pop();
        if(visited[top.from] == 1) continue;

        // cout<<"top: "<<top.from<<endl;

        for(Road road : graph[top.from]) {
            int ori_cost = cost[road.to].dis - cost[road.to].max_road;
            int new_cost = cost[road.from].dis + road.w - max(cost[road.from].max_road, road.w);
            if(ori_cost > new_cost || (ori_cost == new_cost && cost[road.to].visit < cost[road.from].visit + 1)) {
                cost[road.to].dis = cost[road.from].dis + road.w;
                cost[road.to].max_road = max(cost[road.from].max_road, road.w);
                cost[road.to].visit = cost[road.from].visit + 1;
                pq.push(cost[road.to]);
            }
        }
        // for(auto node : cost) {
        //     cout<<"{"<<node.dis<<","<<node.max_road<<","<<node.visit<<"}";
        // }
        // cout<<endl;
        visited[top.from] = 1;
    }

    cout<<cost[n - 1].dis - cost[n - 1].max_road<<" "<<cost[n - 1].visit - 1<<endl;
   
    return 0;
}