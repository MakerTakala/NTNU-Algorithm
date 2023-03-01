#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    for(long long i = 0, a = 0, b = 0; i < t; i++) {
        cin>>a>>b;
        cout<<a + b<<endl;
    }

    return 0;
}