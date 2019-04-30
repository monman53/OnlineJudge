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

#define MAX_T 3.9

inline uint32_t xor128(void){
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123;
    const uint32_t t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

int H, W, D, K;
int r[16000], c[16000];
int m[200][200];

struct S {
    int a, b, c, d;
};

using State = vector<S>;

inline void init(State &s) {
    priority_queue<pair<int, pair<int, int>>> pq;
    inc(i, 0, H){
        inc(j, 0, W){
            if(m[i][j] == -1){
                pq.push({-abs(i-100)-abs(j-100), {i, j}});
            }
        }
    }
    vector<pair<int, pair<int, int>>> v;
    inc(i, 0, D){
        v.pb({abs(r[i]-100)+abs(c[i]-100), {r[i], c[i]}});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    inc(i, 0, K){
        s[i].a = v[i].se.fi;
        s[i].b = v[i].se.se;
        s[i].c = pq.top().se.fi;
        s[i].d = pq.top().se.se;
        pq.pop();
    }
}

inline State neighbor(State &s) {
    State res = s;
    int k = xor128()%K;
    int l = xor128()%D;
    res[k].a = r[l];
    res[k].b = c[l];
    res[k].c = xor128()%H;
    res[k].d = xor128()%W;
    return res;
}

inline int eval(State &s) {
    int m2[200][200];
    inc(i, 0, H) inc(j, 0, W) m2[i][j] = m[i][j];
    inc(i, 0, K){
        swap(m2[s[i].a][s[i].b], m2[s[i].c][s[i].d]);
    }
    vector<pair<int, int>> v(D);
    inc(i, 0, H){
        inc(j, 0, W){
            if(m2[i][j] != -1){
                v[m2[i][j]] = {i, j};
            }
        }
    }

    int cnt = 0;
    inc(i, 1, D){
        cnt += abs(v[i].fi-v[i-1].fi) + abs(v[i].se-v[i-1].se);
    }
    return cnt;
}

inline void output(State &s) {
    inc(i, 0, K){
        cout << s[i].a << " " << s[i].b << " " << s[i].c << " " << s[i].d << endl;
    }
}

inline double T(double sec) {
    double t = sec/MAX_T;
    return pow(0.1, t);
}

inline double prob(double e, double ne, double t) {
    if(e > ne){
        return 1;
    }else{
        return exp((e-ne)/(t*10));
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    clock_t start = clock();

    // input
    cin >> H >> W >> D >> K;
    mset(m, -1);
    inc(i, 0, D){
        cin >> r[i] >> c[i];
        m[r[i]][c[i]] = i;
    }

    // init
    State now(K);
    init(now);
    State best = now;
    int beste = eval(best);
    int nowe = beste;
    State next;


    // annering
    double sec;
    while(true){
        sec = (double)(clock() - start)/CLOCKS_PER_SEC;
        double t = sec/MAX_T;
        if(sec > MAX_T) break;

        //cout << eval(now) << endl;

        next = neighbor(now);
        int nexte = eval(next);
        if(nexte < nowe){
            now = next;
            nowe = nexte;
            if(nowe < beste){
                best = now;
                beste = nowe;
            }
        }
        //}else if((double)xor128()/UINT32_MAX
                 //< prob(nowe, nexte, T(sec))){
            //now = next;
            //nowe = nexte;
        //}
    }

    output(best);

    return 0;
}
