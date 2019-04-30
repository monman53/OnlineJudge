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
    string s;cin >> s;
    int n = s.size();
    int ans = 0;
    inc(i, 0, n-1){
        if(!(s[i] == '2' && s[i+1] == '5' ||
             s[i] == '?' && s[i+1] == '5' ||
             s[i] == '2' && s[i+1] == '?' ||
             s[i] == '?' && s[i+1] == '?')) continue;
        //cout << i << endl;
        int cnt = 2;
        inc(k, 1, n+1){
            int j = i-k;
            if(j < 0) break;
            if(k%2 == 0 && (s[j] == '2' || s[j] == '?')){
                cnt += 2;
            }else if(k%2 == 1 && (s[j] == '5' || s[j] == '?')){
                continue;
            }else{
                break;
            }
        }
        int nxt = i+1;
        inc(k, 2, n+1){
            int j = i+k;
            if(j >= n) break;
            if(k%2 == 1 && (s[j] == '5' || s[j] == '?')){
                cnt += 2;
                nxt = j;
            }else if(k%2 == 0 && (s[j] == '2' || s[j] == '?')){
                continue;
            }else{
                break;
            }
        }
        i = nxt;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
