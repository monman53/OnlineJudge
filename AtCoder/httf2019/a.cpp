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

const int di[] = {0, -1, 0, 1};
const int dj[] = {1, 0, -1, 0};
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

const int n = 500;
const int m = 29;
const int l = 300;
const int n_masu = 50;
vector<string> s;
char brd[m][m];
char ans[m][m];
int cnt[m][m];

int masu_i[n_masu];
int masu_j[n_masu];
int masu_r[m][m];

double total_time = 2.985;

const char op[4] = {'D', 'T', 'L', 'R'};

void init() { 
    inc(i, 0, m){
        inc(j, 0, m){
            cnt[i][j] = 0;
            if(i == 0 || j == 0 || i == m-1 || j == m-1){
                brd[i][j] = '#';
            }else{
                brd[i][j] = '.';
            }
            masu_r[i][j] = -1;
        }
    }
    inc(k, 0, n_masu){
        while(true){
            auto i = xor128()%(m-2)+1;
            auto j = xor128()%(m-2)+1;
            if(brd[i][j] == '.'){
                auto x = xor128();
                char c;
                if(x%100 < 90){
                    c = op[2+xor128()%2];
                    //c = 'L';
                    brd[i][j] = c;
                    masu_i[k] = i;
                    masu_j[k] = j;
                    masu_r[i][j] = k;
                }else{
                    c = '.';
                }
                 
                //if(x%100 < 20){
                    //c = op[xor128()%2];
                //}else{
                    //c = op[2+xor128()%2];
                //}
                break;
            }
        }
    }
}

inline void clear_cnt() {
    mset(cnt, 0);
}

inline void mswap(const pair<pair<int, int>, pair<int, int>> &p) {
    int i = p.fi.fi;
    int j = p.fi.se;
    int i_ = p.se.fi;
    int j_ = p.se.se;

    int x = masu_r[i][j];
    int y = masu_r[i_][j_];

    masu_i[x] = i_;
    masu_j[x] = j_;
    if(y != -1){
        masu_i[y] = i;
        masu_j[y] = j;
    }

    swap(masu_r[i][j], masu_r[i_][j_]);
    swap(brd[i][j], brd[i_][j_]);
}

inline pair<pair<int, int>, pair<int, int>> neighbour() { // {{{
    auto x = xor128()%n_masu;
    int i = masu_i[x];
    int j = masu_j[x];
    int i_ = xor128()%(m-2) + 1;
    int j_ = xor128()%(m-2) + 1;

    mswap({{i, j}, {i_, j_}});

    return {{i, j}, {i_, j_}};
} // }}}

int res_score;

inline void inclement_last_pos(const string &s) { // {{{
    int i = 14;
    int j = 14;
    int dir = 1;
    for(const auto &c : s){
        int dst = 1;
        if(brd[i][j] == 'D') dst = 2;
        if(brd[i][j] == 'T') dst = 3;
        if(c == 'L'){
            if(brd[i][j] == 'R') dst = -1;
            dir = (dir+dst+4)%4;
            continue;
        }
        if(c == 'R'){
            if(brd[i][j] == 'L') dst = -1;
            dir = (dir-dst+4)%4;
            continue;
        }
        if(c == 'S'){
            inc(kk, 0, dst){
                int ni = i + di[dir];
                int nj = j + dj[dir];
                if(brd[ni][nj] != '#'){
                    i = ni;
                    j = nj;
                }
            }
        }
    }
    cnt[i][j]++;
    if(cnt[i][j] == 1){
        res_score += 10;
    }
    if(cnt[i][j] == 2){
        res_score -= 10;
        res_score += 3;
    }
    if(cnt[i][j] == 3){
        res_score -= 3;
        res_score += 1;
    }
    if(cnt[i][j] > 3){
        res_score -= 1;
    }
} // }}}

inline double calc_e() { // {{{
    res_score = 0;
    inc(i, 0, n){
        inclement_last_pos(s[i]);
    }
    return 1.0-res_score/(n*10.0);
} // }}}

void print_ans() { // {{{
    inc(i, 0, m){
        inc(j, 0, m){
            cout << ans[i][j];
        }
        cout << endl;
    }
} // }}}

inline double probability(double e1, double e2, double t){
    return 1;
    if(e1 >= e2){
        return 1;
    }else{
        return exp((e1-e2)/t);
    }
}

inline double temperature(double r) {
    return pow(0.00000005, r);
}

int main() {
    clock_t start = clock();
    cin.tie(0);ios::sync_with_stdio(false);
    int n_, m_, l_;
    cin >> n_ >> m_ >> l_;

    init();

    s.resize(n);
    inc(i, 0, n) cin >> s[i];

    inc(i, 0, m){
        inc(j, 0, m){
            ans[i][j] = brd[i][j];
        }
    }
    double beste = calc_e();
    double e = beste;
    double e_next = beste;

    // routine
    int loop = 0;
    double sec = 0;
    pair<pair<int, int>, pair<int, int>> p;
    clock_t end = clock();
    while(true){
        end = clock();
        sec = (double)(end - start)/CLOCKS_PER_SEC;
        if(sec > total_time) break;

        clear_cnt();
        p = neighbour();

        e_next = calc_e();

        if(e_next < beste){
            //cout << e_next << endl; // #########################
            beste = e_next;
            inc(i, 0, m){
                inc(j, 0, m){
                    ans[i][j] = brd[i][j];
                }
            }
        }else{
            mswap(p);
        }

        //if(double(xor128())/UINT32_MAX < probability(e, e_next, temperature(sec/total_time))){
            //e = e_next;
        //}else{
            //mswap(p);
        //}

        loop++;
    }

    //cout << "loop: " << loop << endl; // ##########################

    print_ans();

    return 0;
}
