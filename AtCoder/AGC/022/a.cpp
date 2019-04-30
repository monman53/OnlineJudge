// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int cnt[26];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    string s;cin >> s;
    int n = s.size();
    if(n != 26){
        for(auto c : s){
            cnt[c-'a']++;
        }
        cout << s;
        inc(i, 0, 26){
            if(!cnt[i]){
                cout << char('a'+i) << endl;
                return 0;
            }
        }
    }else{
        string t = s;
        if(next_permutation(t.begin(), t.end())){
            inc(i, 0, n){
                if(s[i] != t[i]){
                    cout << t[i] << endl;
                    return 0;
                }else{
                    cout << t[i];
                }
            }
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}
