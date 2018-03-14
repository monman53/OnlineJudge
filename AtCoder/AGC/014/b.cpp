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
    int n, m;cin >> n >> m;
    map<int, int> mmap;
    inc(i, 0, m){
        int a, b;cin >> a >> b;
        mmap[a]++;
        mmap[b]++;
    }
    string ans = "YES";
    for(auto kv : mmap){
        if(kv.second%2 != 0) ans = "NO";
    }
    cout << ans << endl;
    return 0;
}
