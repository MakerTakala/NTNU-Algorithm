#include <bits/stdc++.h>
using namespace std;
#define MAX 1005
#define x first
#define y second

int dir[5] = {1, 0, -1, 0, 1};

int n, m; 

pair<int, int> bed, door, lava;

// void show() {
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             cout<<graph[i][j];
//         }
//         cout<<endl;
//     }
//     cout<<endl;
// }

bool BFS(vector<vector<char>> graph) {
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
                    if(graph[nx][ny] == 'C') {
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
                    if(graph[nx][ny] == 'C') {
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
                    lava = {i, j};
                    break;
            }
        }
    }


    int ans = 0;
    queue<pair<int, int>> lava_edge;
    lava_edge.push(lava);

    while(!lava_edge.empty()) {
        //show();
        int size = lava_edge.size();
         while(size--) {
            pair<int, int> top = lava_edge.front(); lava_edge.pop();
            for(int i = 0; i < 4; i++) {
                int nx = top.x + dir[i], ny = top.y + dir[i + 1];
                if(0 <= nx && nx < n && 0 <= ny && ny < m && graph[nx][ny] == 'C') {
                    graph[nx][ny] = 'L';
                    lava_edge.push({nx, ny});
                }
            }
        }
        if(!BFS(graph)) break;
        ans++;
    }

    cout<<(ans == 0 ? -1 : ans)<<endl;


    return 0;
}