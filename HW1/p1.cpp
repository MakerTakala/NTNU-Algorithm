#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int &ele : arr) {
        cin>>ele;
    }
    int type, x, v;
    while(q--) {
        cin>>type;
        if(type == 1) {
            cin>>x>>v;
            arr[x - 1] = v;
        }
        else {
            cin>>x;
            x--;
            int compare = arr[x], lower = 0, same = 0;
            for(int i = 0; i < n; i++) {
                if(arr[i] < compare) lower++;
                else if(arr[i] == compare && i < x) same++;
            }
            cout<<lower + same + 1<<endl;
        }
    }

    return 0;
}