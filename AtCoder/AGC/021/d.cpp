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

int ans[305][305];

int main() {
    std::ios::sync_with_stdio(false);
    string s;cin >> s;
    string t = s;reverse(t.begin(), t.end());
    int n = s.size();

    int k;cin >> k;


    int cnt = 0;
    inc(i, 0, n/2){
        if(k == 0) break;
        if(s[i] != t[i]){
            char c = s[i];
            t[i] = c;
            s[n-i-1] = c;
            //cnt++;
            k--;
        }
    }

    cout << "  ";
    inc(i, 0, n){
        cout << t[i] << " ";
    }
    cout << endl;
    inc(i, 1, n+1){
        cout << s[i-1] << " ";
        inc(j, 1, n+1){
            ans[i][j] = max({ans[i-1][j-1]+(s[i-1]==t[j-1]), ans[i-1][j], ans[i][j-1]});
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    cout << ans[n][n] + cnt << endl;

    return 0;
}
