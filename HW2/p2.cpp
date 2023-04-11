#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int> tree(n);
    for(int &node : tree) {
        cin>>node;
    }
    sort(tree.begin(), tree.end());

    vector<vector<long long int>> dp(n, vector<long long int>(n, 1e11 + 5));

    for(int len = 1; len <= n; len++) {
        for(int left = 0; left + len - 1 < n; left++) {
            int right = left + len - 1;
            for(int root = left; root <= right; root++) {
                long long int left_depth = (left != root ? dp[left][root - 1] : 0);
                long long int right_depth = (right != root ? dp[root + 1][right] : 0);
                dp[left][right] = min(dp[left][right], max(left_depth, right_depth) + tree[root]);
            }
        }
    }
    cout<<dp[0][n - 1]<<endl;

    return 0;
}