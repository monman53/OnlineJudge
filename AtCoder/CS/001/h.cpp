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

// 最長増加部分列 {{{
// Longest Increasing Subsequence
// O(|v|log|v|)
// verified AOJ DPL_1_D
template <typename T>
int lis(vector<T> &v) {
    vector<T> res;
    res.push_back(v[0]);
    int n = v.size();
    for(int i=1;i<n;i++){
        int l = res.size();
        if(v[i] > res[l-1]){
            res.push_back(v[i]);
        }else{
            int ok = l-1;
            int ng = -1;
            while(ok-ng>1){
                int m = (ok+ng)/2;
                if(v[i] <= res[m]){
                    ok = m;
                }else{
                    ng = m;
                }
            }
            res[ok] = v[i];
        }
    }
    return res.size();
}
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> a(n);
    inc(i, 0, n) cin >> a[i];
    cout << lis(a) << endl;
    return 0;
}
