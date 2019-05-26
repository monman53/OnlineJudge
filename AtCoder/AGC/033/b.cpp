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

int h, w;

bool ok(int i, int j) {
    return i >= 0 && i < h && j >= 0 && j < w;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    cin >> h >> w;
    int n;cin >> n;
    int si, sj;cin >> si >> sj;si--;sj--;
    string s, t;cin >> s >> t;
    string ans = "YES";
    char a[] = {'R', 'U', 'L', 'D'};
    char b[] = {'L', 'D', 'R', 'U'};
    inc(k, 0, 4){
        int ci = si;
        int cj = sj;
        inc(i, 0, n){
            if(s[i] == a[k]){
                ci += di[k];
                cj += dj[k];
                if(!ok(ci, cj)) ans = "NO";
            }
            if(t[i] == b[k]){
                ci += di[(k+2)%4];
                cj += dj[(k+2)%4];
                if(!ok(ci, cj)){
                    ci -= di[(k+2)%4];
                    cj -= dj[(k+2)%4];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
