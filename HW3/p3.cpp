#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int dir[5] = {1, 0, -1, 0, 1};

int n, m, ans = 0; 

vector<pair<int, int>> lavas;
pair<int, int> bed, door;


vector<vector<int>> get_flow_time(vector<vector<char>> graph) {
    int time = 1;
    queue<pair<int, int>> lava_edge;
    vector<vector<int>> lava_flow_time(n, vector<int>(m, 0));
    for(auto lava : lavas) {
        lava_edge.push(lava);
    }

    while(!lava_edge.empty()) {
        int size = lava_edge.size();
         while(size--) {
            pair<int, int> top = lava_edge.front(); lava_edge.pop();
            for(int i = 0; i < 4; i++) {
                int nx = top.x + dir[i], ny = top.y + dir[i + 1];
                if(0 <= nx && nx < n && 0 <= ny && ny < m && graph[nx][ny] == 'C') {
                    lava_flow_time[nx][ny] = time;
                    graph[nx][ny] = 'L';
                    lava_edge.push({nx, ny});
                }
            }
        }
        time++;
    }
    return lava_flow_time;
}

bool BFS(vector<vector<char>> graph, vector<vector<int>> lava_flow_time, int limit) {
    queue<pair<int, int>> bed_edge, door_edge;
    bed_edge.push(bed); door_edge.push(door);

    while(!bed_edge.empty() && !door_edge.empty()) {
        int bed_size = bed_edge.size();
        while(bed_size--) {
            pair<int, int> top = bed_edge.front(); bed_edge.pop();
            for(int i = 0; i < 4; i++) {
                int nx = top.x + dir[i], ny = top.y + dir[i + 1];
                if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if(graph[nx][ny] == 'D') return true;
                    if(graph[nx][ny] == 'C' && lava_flow_time[nx][ny] > limit) {
                        graph[nx][ny] = 'B';
                        bed_edge.push({nx, ny});
                    }
                }
            }
        }

        int door_size = door_edge.size();
        while(door_size--) {
            pair<int, int> top = door_edge.front(); door_edge.pop();
            for(int i = 0; i < 4; i++) {
                int nx = top.x + dir[i], ny = top.y + dir[i + 1];
                if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if(graph[nx][ny] == 'B') return true;
                    if(graph[nx][ny] == 'C' && lava_flow_time[nx][ny] > limit) {
                        graph[nx][ny] = 'D';
                        door_edge.push({nx, ny});
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    vector<vector<char>> graph(n, vector<char>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>graph[i][j];
            switch (graph[i][j]){
                case 'B':
                    bed = {i, j};
                    break;
                case 'D':
                    door = {i, j};
                    break;
                case 'L':
                    lavas.push_back({i, j});
                    break;
            }
        }
    }

    vector<vector<int>> lava_flow_time = get_flow_time(graph);
    
    int l = 1, r = 1000005;

    while(l < r) {
        int m = l + (r - l) / 2;
        if(!BFS(graph, lava_flow_time, m)) r = m;
        else l = m + 1;
    }
    ans = l - 1;

    cout<<(ans == 0 ? -1 : ans)<<endl;

    return 0;
}