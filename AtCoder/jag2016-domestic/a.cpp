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
    string ans = "YES";
    int cnt = 0;
    inc(i, 0, n){
        string s;cin >> s;
        if(s == "A"){
            cnt++;
        }else{
            cnt--;
        }
        if(cnt < 0){
            ans = "NO";
        }
    }
    if(cnt != 0){
        ans = "NO";
    }
    cout << ans << endl;
    return 0;
}
