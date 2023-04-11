#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<long long int> dp(n + 1, 0);
    dp[0] = 1;
    for(long long int coin = 1; coin <= n; coin *= 2) {
        for(long long int i = coin; i <= n; i++) {
            dp[i] = ((dp[i] + dp[i - coin]) % MOD);
        }
    }
    cout<<dp[n]<<endl;
}