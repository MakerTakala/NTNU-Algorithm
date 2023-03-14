#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin>>n>>l;
    if((l * l - n) % 3 != 0) cout<<"Can not covered."<<endl;

    vector<vector<int>> grid(l, vector<int>(l, 0));
    vector<int> ans(4, 0);

    int x, y;
    while(n--) {
        cin>>x>>y;
        grid[x][y] = 1;
    }


    return 0;
}