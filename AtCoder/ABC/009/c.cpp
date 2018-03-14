// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, k;cin >> n >> k;
    string s;cin >> s;
    string t = s;
    string ans;
    vector<int> tcnt(26, 0);
    inc(i, 0, n){
        tcnt[s[i]-'a']++;
    }
    inc(i, 0, n){
        sort(t.begin(), t.end());
        //cout << i << " " << t << endl;
        if(t[0] == s[i]){
            ans.pb(t[0]);
            tcnt[t[0]-'a']--;
            t.erase(0, 1);
        }else{
            inc(l, 0, n-i){
                int cnt = 0;
                tcnt[t[l]-'a']--;
                auto v = tcnt;
                inc(j, i+1, n){
                    if(v[s[j]-'a'] > 0){
                        v[s[j]-'a']--;
                    }
                }
                inc(j, 0, 26){
                    cnt += v[j];
                }
                if(t[l] != s[i]) cnt++;
                //cout << l << " " << cnt << " " << k << endl;
                if(cnt > k){
                    tcnt[t[l]-'a']++;
                    continue;
                }else{
                    ans.pb(t[l]);
                    if(t[l] != s[i]) k--;
                    t.erase(l, 1);
                    break;
                }
            }
        }
        //cout << ans << " " << k << endl;
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}
