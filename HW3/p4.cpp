#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    cin>>n>>l;
    vector<pair<int, int>> times(n);
    for(auto &time : times) {
        cin>>time.first>>time.second;
    }

    sort(times.begin(), times.end(), [](auto &a, auto &b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    int count = 0, sum = 0, next_right = 0;
    pair<int, int> cur = {0, 0};
    for(int i = 0; i < n; i++) {
        if(times[i].first == times[i].second) continue;
        if(times[i].first <= cur.second) {
            next_right = max(next_right, times[i].second);
            continue;
        }
        if(next_right > cur.second) {
            cur.second = next_right;
            count++;
            i--;
        }
        else {
            sum += cur.second - cur.first;
            cur = times[i];
            count++;
        }
        next_right = cur.second;
        
    }
    if(next_right > cur.second) {
        cur.second = next_right;
        count++;
    }
    sum += cur.second - cur.first;

    cout<<count<<" "<<l - sum<<endl;    
    return 0;
}