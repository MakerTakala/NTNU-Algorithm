#include <bits/stdc++.h>
#define Block pair<int, int>
#define x first
#define y second
using namespace std;

vector<int> add(vector<int> a, vector<int> b) {
    for(int i = 0; i < a.size(); i++) {
        a[i] += b[i];
    }
    return a;
}

bool fail = false;

vector<int> solver(vector<Block> blacks, int puzzle_size) {
    if(puzzle_size == 1) return vector<int>(4, 0);
    if(blacks.size() == 1) {
        
    }

}

int main() {
    int n, l;
    cin>>n>>l;
    if(n % 3 != 1) cout<<"Can not covered."<<endl;

    vector<Block> blacks(l);
    vector<int> ans(4, 0);

    for(Block &black : blacks) {
        cin>>black.x>>black.y;
    }



    return 0;
}