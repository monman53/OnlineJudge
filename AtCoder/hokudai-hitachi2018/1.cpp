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

inline uint32_t xor128(void){
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123;
    const uint32_t t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

int n, k;
int s;

using P = pair<int, int>;

int main() {
    cin >> n >> k;
    s = n;
    map<P, int> mp;
    map<P, int> mp2;
    int sum = 0;
    inc(i, 0, k){
        int d, c;
        cin >> d >> c;
        vector<int> v(d, -1);
        inc(j, 0, d){
            cin >> v[j];
        }

        if(d == 0){
            sum += c;
        }else if(d == 1){
            mp[P(v[0], -1)] += c;
        }else if(d == 2){
            mp[P(v[0], v[1])] += c;
        }else{
            if(c > 0){
                vector<pair<int, P>> vv;
                inc(ii, 0, d){
                    inc(jj, ii+1, d){
                        if(mp.find(P(v[ii], v[jj])) == mp.end()) continue;
                        vv.pb({abs(mp[P(v[ii], v[jj])]+c), P(v[ii], v[jj])});
                    }
                }
                if(vv.size() > 0){
                    sort(vv.begin(), vv.end());
                    mp[vv[0].se] += c;
                    continue;
                }
                //sum += c;
                while(true){
                    int ii = xor128()%d;
                    int jj = xor128()%d;
                    if(ii >= jj) continue;
                    mp[P(v[ii], v[jj])] += c;
                    break;
                }
            }else{
                s++;
                mp[P(s, -1)] += (d-1)*(-c);
                inc(ii, 0, d){
                    mp[P(v[ii], s)] += c;
                }
            }
        }
    }
    mp[P(-1, -1)] += max(sum, 1);
    for(auto kv : mp){
        auto k = kv.fi;
        auto c = kv.se;
        if(c == 0) continue;
        mp2[k] = c;
    }
    cout << s << " " << mp2.size() << endl;
    for(auto kv: mp2){
        auto k = kv.fi;
        auto c = kv.se;
        if(k.fi == -1){
            cout << "0 " << c << endl;
        }else if(k.se == -1){
            cout << "1 " << c << " " << k.fi << endl;
        }else{
            cout << "2 " << c << " " << k.fi << " " << k.se << endl;
        }
    }
    return 0;
}
