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

inline uint32_t rnd() {
    return xor128();
}

static double UINT32_MAX_R = (double)1.0/UINT32_MAX;
inline double uniform() {
    return xor128()*UINT32_MAX_R;
}

#define MAX_T 5.9
#define INTERVAL 1000

inline double temperature(double t) {
    //return 1-t;
    return pow(0.01, t);
}

inline double prob(double e, double ne, double tmp) {
    if(e < ne){
        return 1;
    }else{
        return exp((ne-e)*1000000/(tmp));
    }
}

using P = pair<pair<int, int>, int>;

inline int dist(int si, int sj, int ti, int tj) {
    return abs(ti-si)+abs(tj-sj);
}

struct S {
    P v[1000];
    int sum[100][100];
    double e;
};

int A[100][100];
int N = 100;
double SUM = 0;
S stat, sbest;

inline double eval(S &s) {
    return s.e;
}

void init(S &s) {
    inc(k, 0, 1000){
        int i = rnd()%N;
        int j = rnd()%N;
        s.v[k] = P{{i, j}, max(1, min(100, (int)(A[i][j]*0.005)))};
    }

    int ssum = 0;
    inc(i, 0, N){
        inc(j, 0, N){
            int cnt = 0;
            inc(k, 0, 1000){
                cnt += max(0, s.v[k].se-abs(s.v[k].fi.fi-i)-abs(s.v[k].fi.se-j));
            }
            s.sum[i][j] = cnt;

            ssum += abs(A[i][j]-s.sum[i][j]);
        }
    }
    s.e = ssum/SUM;
}

inline bool neighbour_(S &s, int idx, double a, double b, int k, bool flag) {
    bool res = true;

    inc(i, 0, N){
        inc(j, 0, N){
            s.sum[i][j] -= max(0, s.v[idx].se-abs(s.v[idx].fi.fi-i)-abs(s.v[idx].fi.se-j));
        }
    }

    if(a < 0.1){
        int ni = s.v[idx].fi.fi + di[k];
        int nj = s.v[idx].fi.se + dj[k];
        if(flag){
            if(ni >= 0 && ni < N && nj >= 0 && nj < N){
                s.v[idx].fi.fi = ni;
                s.v[idx].fi.se = nj;
            }else{
                res = false;
            }
        }else{
            s.v[idx].fi.fi += di[(k+2)%4];
            s.v[idx].fi.se += dj[(k+2)%4];
        }
    }else{
        if(s.v[idx].se == 0){
            s.v[idx].se++;
        }else if(s.v[idx].se == 100){
            s.v[idx].se--;
        }else{
            if(b < 0.5){
                if(flag){
                    s.v[idx].se++;
                }else{
                    s.v[idx].se--;
                }
            }else{
                if(flag){
                    s.v[idx].se--;
                }else{
                    s.v[idx].se++;
                }
            }
        }
    }

    int ssum = 0;
    inc(i, 0, N){
        inc(j, 0, N){
            s.sum[i][j] += max(0, s.v[idx].se-abs(s.v[idx].fi.fi-i)-abs(s.v[idx].fi.se-j));
            ssum += abs(A[i][j]-s.sum[i][j]);
        }
    }
    s.e = ssum/SUM;

    return res;
}

inline S neighbour(S &s) { // {{{
    S res = s;
    int idx = rnd()%1000;

    inc(i, 0, N){
        inc(j, 0, N){
            res.sum[i][j] -= max(0, res.v[idx].se-abs(res.v[idx].fi.fi-i)-abs(res.v[idx].fi.se-j));
        }
    }

    if(uniform() < 0.1){
        int k = rnd()%4;
        int ni = s.v[idx].fi.fi + di[k];
        int nj = s.v[idx].fi.se + dj[k];
        if(ni >= 0 && ni < N && nj >= 0 && nj < N){
            res.v[idx].fi.fi = ni;
            res.v[idx].fi.se = nj;
        }
    }else{
        if(s.v[idx].se == 0){
            res.v[idx].se++;
        }else if(s.v[idx].se == 100){
            res.v[idx].se--;
        }else{
            if(uniform() < 0.5){
                res.v[idx].se++;
            }else{
                res.v[idx].se--;
            }
        }
    }

    int ssum = 0;
    inc(i, 0, N){
        inc(j, 0, N){
            res.sum[i][j] += max(0, res.v[idx].se-abs(res.v[idx].fi.fi-i)-abs(res.v[idx].fi.se-j));
            ssum += abs(A[i][j]-res.sum[i][j]);
        }
    }
    res.e = ssum/SUM;

    return res;
} // }}}

void output(S &s) {
    vector<P> ans;
    inc(i, 0, 1000){
        if(s.v[i].se > 0){
            ans.pb(s.v[i]);
        }
    }
    cout << ans.size() << endl;
    for(auto a : ans){
        cout << a.fi.se << " " << a.fi.fi << " " << a.se << endl;
    }
}

int main() {
    clock_t start = clock();

    // input
    inc(i, 0, N){
        inc(j, 0, N){
            cin >> A[i][j];
            SUM += A[i][j];
        }
    }

    // Simulated annealing
    double tsec = 0;
    double time = 0;
    double temp = temperature(0);
    init(stat);
    sbest = stat;
    for(int step=0;;step++){
        if(step%INTERVAL == 0){
            tsec = (double)(clock() - start)/CLOCKS_PER_SEC;
            if(tsec > MAX_T){
                break;
            }
            time = tsec/MAX_T;
            temp = temperature(time);
            cout << step << " " << eval(sbest) << endl;
        }

        //snext = neighbour(sbest);
        int idx = rnd()%1000;
        double a = uniform();
        double b = uniform();
        int k = rnd()%4;
        
        double e = stat.e;
        bool flag = neighbour_(stat, idx, a, b, k, true);
        double ne = stat.e;

        //cout << prob(e, ne, temp) << endl;

        if(eval(stat) < eval(sbest)){
            sbest = stat;
        }else if(uniform() < prob(e, ne, temp)){
            //if(flag){
                //neighbour_(stat, idx, a, b, k, false);
            //}
        }else{
            stat = sbest;
        }
        //cout << temp << endl;
    }

    // output
    //output(sbest);

    return 0;
}
