// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(r);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> a(n);
    inc(i, 0, n) cin >> a[i];
    set<int> st;
    st.insert(a[0]);
    int ans = 1;
    int l = 0;
    int r = 1;
    while(r<n){
        if(st.find(a[r]) == st.end()){
            st.insert(a[r]);
            r++;
            ans = max(ans, r-l);
        }else{
            st.erase(a[l]);
            l++;
        }
    }
    cout << ans << endl;
    return 0;
}
