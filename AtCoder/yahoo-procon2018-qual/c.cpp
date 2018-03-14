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

LL n;
LL x[18], c[18], v[18];
int ng[18];

//LL solve(int k) {
    //LL res = 0;
    ////bitset<18> bit(k);
    //LL m = 0;
    //int p = 0;
    //inc(i, 0, n){
        //if(k%2 == 0){

        //}else{
            //m += x[p];
            //p++;

            //LL mmax = 0;
            //int maxj = -1;
            //inc(j, 0, n){
                //if(ng[j]) continue;
            //}
        //}
    //}
    //return res;
//}

LL dfs(int i, int k, LL m, LL value) {
    LL res = 0;
    if(i == n){
        return value;
    }

    // 2
    vector<pair<double, pair<LL, int>>> vv;
    int ngi = -1;
    for(int j=0;j<n;j++){
        if(ng[j]) continue;
        if(m+x[k] < c[j]) continue;
        //vv.pb({(double)v[j]/c[j], {v[j], j}});
        vv.pb({v[j], {v[j], j}});
    }
    if((int)vv.size() == 0){
        for(int j=0;j<n;j++){
            if(ng[j]) continue;
            //vv.pb({(double)v[j]/c[j], {v[j], j}});
            vv.pb({v[j], {v[j], j}});
        }
        sort(vv.begin(), vv.end());
        reverse(vv.begin(), vv.end());
        if((int)vv.size() > 0){
            ngi = vv[0].se.se;
        }else{
            return value;
        }
    }else{
        sort(vv.begin(), vv.end());
        reverse(vv.begin(), vv.end());
        ngi = vv[0].se.se;
    }
    ng[ngi] = 1;
    res = dfs(i+1, k+1, m+x[k], value);
    ng[ngi] = 0;


    // 3
    vector<pair<double, pair<LL, int>>> uu;
    for(int j=0;j<n;j++){
        if(ng[j]) continue;
        if(c[j] > m) continue;
        uu.pb({(double)v[j]/c[j], {v[j], j}});
        //uu.pb({v[j], {v[j], j}});
    }
    sort(uu.begin(), uu.end());
    reverse(uu.begin(), uu.end());

    if((int)uu.size() == 0){
        res = max(res, dfs(i+1, k, m, value));
    }else{
        int ngj = uu[0].se.se;
        ng[ngj] = 1;
        res = max(res, dfs(i+1, k, m-c[ngj], value+v[ngj]));
        ng[ngj] = 0;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    inc(i, 0, n){
        cin >> x[i];
    }
    inc(i, 0, n){
        cin >> c[i];
    }
    inc(i, 0, n){
        cin >> v[i];
    }

    //LL mmax = 0;
    //inc(i, 0, n){
        //mset(ng, 0);
        //mmax = max(mmax, solve(i));
    //}
    //cout << mmax << endl;

    cout << dfs(0, 0, 0, 0) << endl;

    return 0;
}
