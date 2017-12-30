// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, x;cin >> n >> x;
    if(x == 2*n-1 || x == 1){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        if(n == 2){
            for(int i=1;i<=3;i++){
                cout << i << endl;
            }
        }else{
            vector<int> ans;
            for(int i=1;i<=2*n-1;i++){
                if(x == 2 && x-1 <= i && i <= x+2) continue;
                if(x != 2 && x-2 <= i && i <= x+1) continue;
                ans.push_back(i);
            }
            for(int i=0;i<n-2;i++){
                cout << ans[i] << endl;
            }
            if(x == 2){
                cout << x+1 << endl;
                cout << x << endl;
                cout << x-1 << endl;
                cout << x+2 << endl;
            }else{
                cout << x-1 << endl;
                cout << x << endl;
                cout << x+1 << endl;
                cout << x-2 << endl;
            }
            for(int i=n-2;i<2*n-1-4;i++){
                cout << ans[i] << endl;
            }
        }
    }
    return 0;
}
