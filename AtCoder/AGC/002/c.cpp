// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    LL l;cin >> l;
    vector<LL> a(n);
    inc(i, 0, n) cin >> a[i];
    vector<int> ans;
    inc(i, 0, n-1){
        if(a[i]+a[i+1] >= l){
            ans.push_back(i);
            for(int j=i-1;j>=0;j--) ans.push_back(j);
            for(int j=i+1;j<n-1;j++) ans.push_back(j);
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    if(ans.size()){
        cout << "Possible" << endl;
        for(auto a : ans){
            cout << a+1 << endl;
        }
    }else{
        cout << "Impossible" << endl;
    }
    return 0;
}
