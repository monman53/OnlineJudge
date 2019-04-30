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

string cc[100];
int cnt[101][101];

bool solve() {
    int r, c;cin >> r >> c;
    int h, v;cin >> h >> v;
    int sum = 0;
    inc(i, 0, r) cin >> cc[i];
    mset(cnt, 0);

    vector<int> cntr(r, 0), cntc(c, 0);
    inc(i, 0, r){
        inc(j, 0, c){
            cnt[i+1][j+1] = cnt[i+1][j] + cnt[i][j+1] - cnt[i][j];
            if(cc[i][j] == '@'){
                cntr[i]++;
                cntc[j]++;
                sum++;
                cnt[i+1][j+1]++;
            }
        }
    }
    
    if(sum%(h+1) != 0 || sum%(v+1) != 0 || sum%((h+1)*(v+1) != 0)){
        return false;
    }


    int now = 0;
    vector<int> vr;
    vr.pb(0);
    inc(i, 0, r){
        now += cntr[i];
        if(now < sum/(h+1)){
            continue;
        }
        if(now > sum/(h+1)){
            return false;
        }
        if(i != r-1) vr.pb(i+1);
        now = 0;
    }
    if(now != 0){
        return false;
    }
    vr.pb(r);

    now = 0;
    vector<int> vc;
    vc.pb(0);
    inc(i, 0, c){
        now += cntc[i];
        if(now < sum/(v+1)){
            continue;
        }
        if(now > sum/(v+1)){
            return false;
        }
        if(i != c-1) vc.pb(i+1);
        now = 0;
    }
    if(now != 0){
        return false;
    }
    vc.pb(c);

    inc(i, 1, h+2){
        inc(j, 1, v+2){
            int a = cnt[vr[i]][vc[j]] - cnt[vr[i-1]][vc[j]] - cnt[vr[i]][vc[j-1]] + cnt[vr[i-1]][vc[j-1]];
            //cout << vr[i] << ":" << vc[j] << " " << a << endl;
            if(a != sum/((h+1)*(v+1))) return false;
        }
    }

    return true;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(k, 0, t){
        auto ans = solve();
        cout << "Case #" << k+1 << ": " << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    }
    return 0;
}
