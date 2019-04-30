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

long long count(long long n, int m) {
    long long res = 0;
    for(long long i=10;i<=n*10;i*=10){
        res += n/i*i/10;
        res += min(max(n%i+1-i*m/10, 0LL), i/10);
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    cout << count(n, 1) << endl;
    return 0;
}
