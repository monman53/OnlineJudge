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

int n, k;
int s;

int main() {
    cin >> n >> k;
    s = n;
    vector<pair<pair<int, int>, vector<int>>> output;
    int sum = 0;
    inc(i, 0, k){
        int d, c;
        cin >> d >> c;
        vector<int> v(d);
        inc(j, 0, d){
            cin >> v[j];
        }

        if(d == 0){
            sum += c;
        }else if(d == 1 || d == 2){
            output.pb({{d, c}, v});
        }else{
            if(c > 0){
                sum += c;
            }else{
                s++;
                output.pb({{1, (d-1)*(-c)}, {s}});
                inc(m, 0, d){
                    output.pb({{2, c}, {v[m], s}});
                }
            }
        }
    }
    output.pb({{0, max(sum, 1)}, {}});
    int l = int(output.size());
    cout << s << " " << l << endl;
    inc(i, 0, l){
        int d = output[i].fi.fi;
        int c = output[i].fi.se;
        auto v = output[i].se;
        cout << d << " " << c;
        inc(j, 0, d){
            cout << " " << v[j];
        }
        cout << endl;
    }
    return 0;
}
