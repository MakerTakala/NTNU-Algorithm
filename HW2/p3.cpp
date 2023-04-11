#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin>>n>>m>>r;
    vector<pair<int, int>> flights(r);
    for(auto &flight: flights) {
        cin>>flight.first>>flight.second;
    }
    sort(flights.begin(), flights.end(), [](auto &a, auto &b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    vector<pair<int, int>> dp;
    for(auto flight : flights) {
        if(dp.empty() || dp.back().second < flight.second) {
            dp.push_back(flight);
        }
        else {
            *lower_bound(dp.begin(), dp.end(), flight, [](auto &a, auto &b) { return a.second < b.second; }) = flight;
        }
    }
    cout<<dp.size()<<endl;

    return 0;
}