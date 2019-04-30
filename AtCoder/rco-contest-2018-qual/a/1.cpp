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

int N, K, H, W, T;
char c[100][50][50];
int si[100], sj[100];

using State = vector<int>;

inline void init(vector<int> &com) {
    inc(i, 0, T){
        com[i] = xor128()%4;
    }
};

inline void output(vector<int> m, vector<int> com) {
    inc(i, 0, 8){
        printf("%d", m[i]);
        if(i != 7){
            printf(" ");
        }
    }
    printf("\n");
    inc(i, 0, T){
        if(com[i] == 0) printf("R");
        if(com[i] == 1) printf("U");
        if(com[i] == 2) printf("L");
        if(com[i] == 3) printf("D");
    }
    printf("\n");
}

inline pair<int, vector<int>> eval(vector<int> &com) {
    int f[50][50];
    vector<pair<int, int>> v(N);

    // calc
    inc(i, 0, N){
        mset(f, 0);
        int cnt = 0;
        int ci = si[i];
        int cj = sj[i];
        inc(k, 0, T){
            int ni = ci + di[com[k]];
            int nj = cj + dj[com[k]];
            if(c[i][ni][nj] == '#'){
                continue;
            }
            if(c[i][ni][nj] == 'x'){
                break;
            }
            if(c[i][ni][nj] == 'o' && f[ni][nj] == 0){
                f[ni][nj] = 1;
                cnt++;
            }
            ci = ni;
            cj = nj;
        }
        v[i] = {cnt, i};
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    pair<int, vector<int>> res = {0, {}};
    inc(i, 0, 8){
        res.fi += v[i].fi;
        res.se.pb(v[i].se);
    }
    return res;
}

vector<int> neighbor(vector<int> &com) {
    auto res = com;
    res[xor128()%2500] = xor128()%4;
    return res;
}

inline double temper(double sec) {
    double t = sec/MAX_T;
    //return (1.0-t)*0.5;
    return exp(-t/0.5)*0.5;
}

int main() {
    std::ios::sync_with_stdio(false);
    clock_t start = clock();

    // input
    cin >> N >> K >> H >> W >> T;
    inc(i, 0, N){
        inc(j, 0, H){
            string s;cin >> s;
            inc(k, 0, W){
                c[i][j][k] = s[k];
                if(s[k] == '@'){
                    si[i] = j;
                    sj[i] = k;
                }
            }
        }
    }

    // init
    State now(2500);
    init(now);
    State best = now;

    // annering
    double sec;
    while(true){
        sec = (double)(clock() - start)/CLOCKS_PER_SEC;
        if(sec > MAX_T) break;

        //cout << eval(now).fi << endl;

        auto next = neighbor(now);
        if(eval(next).fi > eval(best).fi){
            best = next;
        }else if(eval(best).fi - eval(next).fi < 2){
            now = next;
        }
        //}else if((double)xor128()/UINT32_MAX < temper(sec)){
            //now = next;
        //}
    }

    // output
    auto m = eval(best).se;
    output(m, best);
    return 0;
}
