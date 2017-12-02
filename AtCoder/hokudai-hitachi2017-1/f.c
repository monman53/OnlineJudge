#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <math.h>

double MAX_T = 9.95;
double UINT32_MAX_R = (double)1.0/UINT32_MAX;
double ALPHA = 0.995;
double T     = 1.0;
double PROB  = 1.0;
int DIFF     = 9;

double sec = 0.0;

int full = 1;
int sparse = 1;

int n, ne, m, me;
int gh, geh;
int g[500][500], ge[3600][3600];
int gl[500][500];int gn[500];
int gel[3600][3600];int gen[3600];
int u[20000], v[20000];
int w[500][500];

inline double exp_(double x) {
    return 1.0+x*(1.0+x*0.5);
}

inline uint32_t xor128(void){
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123; 
    const uint32_t t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

struct State;
void state_init(struct State *s);
int state_score(const struct State *s);
inline int state_swap_s(const struct State *s, int i, int j);
inline void state_swap(struct State *s, int i, int j);

struct State {
    int f[500];
    int fr[3600];
    int score;
};

void state_init(struct State *s) {
    int pad = (geh - gh)/2;
    memset(s->fr, -1, sizeof(s->fr));
    for(int i=0;i<n;i++){
        s->f[i] = (i/gh+pad)*geh + i%gh + pad;
    }
    for(int i=0;i<n;i++){
        s->fr[s->f[i]] = i;
    }
    s->score = state_score(s);
}

inline int state_score(const struct State *s) {
    int ret = 0;
    for(int i=0;i<m;i++){
        int uu = s->f[u[i]];
        int vv = s->f[v[i]];
        if(ge[uu][vv]){
            ret += w[u[i]][v[i]];
        }
    }
    return ret;
}

inline int state_swap_s(const struct State *s, int i, int j) {
    int diff = 0;
    for(int k=0;k<gen[s->f[i]];k++){
        const int kr = s->fr[gel[s->f[i]][k]];
        if(kr == -1) continue;
        diff -= w[i][kr];
        diff += w[j][kr];
    }
    for(int k=0;k<gen[s->f[j]];k++){
        const int kr = s->fr[gel[s->f[j]][k]];
        if(kr == -1) continue;
        diff -= w[j][kr];
        diff += w[i][kr];
    }
    if(ge[s->f[i]][s->f[j]]) diff += 2*w[i][j];
    return diff;
    //if(s->score != state_score(&s) printf("!!!!!\n");
}

inline void state_swap(struct State *s, int i, int j) {
    // swap f[i], f[j]
    int tmp = s->f[i];
    s->f[i] = s->f[j];
    s->f[j] = tmp;

    // swap fr[i], fr[j]
    tmp = s->fr[s->f[i]];
    s->fr[s->f[i]] = s->fr[s->f[j]];
    s->fr[s->f[j]] = tmp;
}

int main() {
    clock_t start = clock();

    memset(g, 0, sizeof(g));
    memset(gn, 0, sizeof(gn));
    memset(ge, 0, sizeof(ge));
    memset(gen, 0, sizeof(gen));
    memset(w, 0, sizeof(w));

    //----------------
    // input
    //----------------
    // {{{
    
    // G
    scanf("%d %d", &n, &m);
    for(int i=0;i*i<n;i++){
        gh = i;
    }
    gh++;
    for(int i=0;i<m;i++){
        int uu, vv, ww;scanf("%d %d %d", &uu, &vv, &ww);uu--;vv--;
        u[i] = uu;v[i] = vv;
        g[uu][vv] = g[vv][uu] = 1;
        gl[uu][gn[uu]] = vv;gn[uu]++;
        gl[vv][gn[vv]] = uu;gn[vv]++;
        w[uu][vv] = w[vv][uu] = ww;
    }
    for(int i=0;i<n;i++){
        if(gn[i] != n-1){
            full = 0;
        }
        if(gn[i] > 8){
            sparse = 0;
        }
    }

    // GE
    scanf("%d %d", &ne, &me);
    for(int i=0;i<me;i++){
        int a, b;scanf("%d %d", &a, &b);a--;b--;
        ge[a][b] = ge[b][a] = 1;
        gel[a][gen[a]] = b;gen[a]++;
        gel[b][gen[b]] = a;gen[b]++;
    }
    for(int i=0;i*i<=ne;i++) geh = i;
    // }}}

    //----------------
    // calc
    //----------------
    // {{{

    // params

    // init
    int count = 0;
    clock_t end = clock();
    struct State state;state_init(&state);
    struct State best = state;

    // routine
    while(1){
        if(count%100000 == 0){
            end = clock();
            sec = (double)(end - start)/CLOCKS_PER_SEC;
            T   = pow(ALPHA, sec/MAX_T);
            if(full){
                PROB = 0.4-0.2*(sec/MAX_T);
                DIFF = 8;
            }else if(sparse){
                ///PROB = 0.4-0.4*(sec/MAX_T);
                //PROB= 0.4;
                PROB = 0.3-0.3*(sec/MAX_T);
                DIFF = 6;
            }else{
                PROB = 0.6-0.4*(sec/MAX_T); // 決定
                DIFF = 9;
            }
            if(sec > MAX_T) break;
            //best.print();
            //cout << best.score_() << " " << best.score << endl;
            /*printf("%d\n", best.score);*/
        }
        count++;

        const int i = xor128()%n;
        const int j = xor128()%n;
        const int diff = state_swap_s(&state, i, j);

        if(diff >= 0){
            state.score += diff;
            state_swap(&state, i, j);
            if(state.score > best.score){
                best = state;
            }
        }else if(diff > -DIFF){
            if(xor128()*UINT32_MAX_R <= PROB){
                state.score += diff;
                state_swap(&state, i, j);
            }
        }
    }
    // }}}

    while(1){
        int flag = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                const int diff = state_swap_s(&best, i, j);
                if(diff > 0){
                    //cout << "!!!!!!" << b-a << endl;
                    flag = 1;
                    best.score += flag;
                    state_swap(&best, i, j);
                }
            }
        }
        end = clock();
        sec = (double)(end - start)/CLOCKS_PER_SEC;
        if(sec > MAX_T+0.035) break;
        if(!flag) break;
    }

    //----------------
    // output
    //----------------
    for(int i=0;i<n;i++){
        printf("%d %d\n", i+1, best.f[i]+1);
    }

    return 0;
}
