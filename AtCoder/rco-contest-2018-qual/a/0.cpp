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

struct State {
    int m[8];
    int com[2500];

    inline void output() {
        inc(i, 0, 8){
            printf("%d", m[i]);
            if(i != 7){
                printf(" ");
            }
        }
        printf("\n");
        inc(i, 0, 2500){
            if(com[i] == 0) printf("R");
            if(com[i] == 1) printf("U");
            if(com[i] == 2) printf("L");
            if(com[i] == 3) printf("D");
        }
        printf("\n");
    }
};

inline void init(State &state) {
    inc(i, 0, 8){
        state.m[i] = i;
    }
    inc(i, 0, 2500){
        state.com[i] = xor128()%4;
    }
};

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
            }
        }
    }

    // init
    State state;
    init(state);

    // output
    state.output();
    return 0;
}
