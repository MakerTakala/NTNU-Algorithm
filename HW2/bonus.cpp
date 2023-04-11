#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    vector<int> froms(n), tos(m);
    
    
    for(int i = 0; i < n; i++) {
        cin>>froms[i];
    }
    for(int i = 0; i < m; i++) {
        cin>>tos[i];
    }
    

    return 0;
}