// header {{{
#include <climits>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
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

inline uint32_t rnd() {
    return xor128();
}

static double UINT32_MAX_R = (double)1.0/UINT32_MAX;
inline double uniform() {
    return xor128()*UINT32_MAX_R;
}

#define MAX_T 5.9
#define INTERVAL 1

inline double temperature(double t) {
    //return 1-t;
    return pow(0.1, t);
}

inline double prob(double e, double ne, double tmp) {
    // ne > e
    return exp(-(ne-e)*100/(tmp));
}

using P = pair<pair<int, int>, int>;

inline int dist(int si, int sj, int ti, int tj) {
    return abs(ti-si)+abs(tj-sj);
}

struct Seq {
    int op[1000];
    int j1[1000];
    int i1[1000];
    int j2[1000];
    int i2[1000];
    double e;
};

void init(Seq &s) { // {{{
    inc(i, 0, 1000){
        double p = uniform();
        if(p < 0.1){
            s.op[i] = 0;
        }else if(p < 0.2){
            s.op[i] = 1;
        }else if(p < 0.3){
            s.op[i] = 2;
        }else if(p < 0.5){
            s.op[i] = 3;
        }else if(p < 0.7){
            s.op[i] = 4;
        }else if(p < 0.805){
            s.op[i] = 5;
        }else if(p < 1.0){
            s.op[i] = 6;
        }
        s.op[i] = rnd()%7;
        int a, b, c, d;
        switch(s.op[i]){
            case 0: // road
                a = rnd()%50;
                b = rnd()%50;
                c = rnd()%50;
                if(rnd()%2 == 0){
                    s.i1[i] = s.i2[i] = a;
                    s.j1[i] = min(b, c);
                    s.j2[i] = max(b, c);
                }else{
                    s.j1[i] = s.j2[i] = a;
                    s.i1[i] = min(b, c);
                    s.i2[i] = max(b, c);
                }
                break;
            case 1: // plant
                s.j1[i] = rnd()%50;
                s.i1[i] = rnd()%50;
                break;
            case 2: // harvest
                a = rnd()%50;
                b = rnd()%50;
                s.j1[i] = min(a, b);
                s.j2[i] = max(a, b);
                c = rnd()%50;
                d = rnd()%50;
                s.i1[i] = min(c, d);
                s.i2[i] = max(c, d);
                break;
            case 3: // destroy
                a = rnd()%50;
                b = rnd()%50;
                s.j1[i] = min(a, b);
                s.j2[i] = max(a, b);
                c = rnd()%50;
                d = rnd()%50;
                s.i1[i] = min(c, d);
                s.i2[i] = max(c, d);
                break;
            case 4: // growup
                s.j1[i] = rnd()%10+1;
                break;
            case 5: // warpgate
                s.j1[i] = rnd()%50;
                s.i1[i] = rnd()%50;
                break;
            case 6: // work
                break;
        }
    }
} // }}}

void print(int c[][50]) { // {{{
    inc(i, 0, 50){
        inc(j, 0, 50){
            switch(c[i][j]){
                case 0:
                    printf(".");
                    break;
                case 100:
                    printf("#");
                    break;
                case 200:
                    printf("W");
                    break;
                case 300:
                    printf("+");
                    break;
                default:
                    printf("v");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}// }}}


string A[50];

void update_d(int d[][50], int c[][50]){ // {{{
    while(true){
        bool flag = true;
        inc(i, 0, 50){
            inc(j, 0, 50){
                int cost = 10;
                if(c[i][j] == 300) cost = 1;
                if(c[i][j] == 100) cost = 50;
                inc(k, 0, 4){
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if(ni >= 0 && ni < 50 && nj >= 0 && nj < 50){
                        if(d[ni][nj] + cost < d[i][j]){
                            d[i][j] = d[ni][nj] + cost;
                            flag = false;
                        }
                    }
                }
            }
        }
        if(flag) break;
    }
} // }}}

struct SEQ {
    int op;
    int j1, i1;
    int j2, i2;
};

void output(vector<SEQ> &s) { // {{{
    inc(i, 0, 1000){
        switch(s[i].op){
            case 0: // road
                printf("road %d %d %d %d\n", s[i].j1+1, s[i].i1+1, s[i].j2+1, s[i].i2+1);
                break;
            case 1: // plant
                printf("plant %d %d\n", s[i].j1+1, s[i].i1+1);
                break;
            case 2: // harvest
                printf("harvest %d %d %d %d\n", s[i].j1+1, s[i].i1+1, s[i].j2+1, s[i].i2+1);
                break;
            case 3: // destroy
                printf("destroy %d %d %d %d\n", s[i].j1+1, s[i].i1+1, s[i].j2+1, s[i].i2+1);
                break;
            case 4: // growup
                printf("growup %d\n", s[i].j1);
                break;
            case 5: // warpgate
                printf("warpgate %d %d\n", s[i].j1+1, s[i].i1+1);
                break;
            case 6: // work
                printf("work\n");
                break;
        }
    }
} // }}}

double eval(vector<SEQ> &s) { // {{{
    int c[50][50];
    int tmp[50][50];
    int d[50][50];
    inc(i, 0, 50){
        inc(j, 0, 50){
            if(A[i][j] == '.') c[i][j] = 0;
            if(A[i][j] == '#') c[i][j] = 100;
            if(A[i][j] == 'W') c[i][j] = 200;
            d[i][j] = INF;
            if(A[i][j] == 'W'){
                d[i][j] = 0;
            }
        }
    }
    int m = 100;
    int w = 100;
    int t = 0;
    int w_max = 100;
    update_d(d, c);

    inc(o, 0, 1000){
        w = w_max;

        inc(i, 0, 50){
            inc(j, 0, 50){
                tmp[i][j] = c[i][j];
            }
        }
        inc(i, 0, 50){
            inc(j, 0, 50){
                if(tmp[i][j] < 100){
                    bool flag = false;
                    inc(k, 0, 4){
                        int ni = i + di[k];
                        int nj = j + dj[k];
                        if(ni >= 0 && ni < 50 && nj >= 0 && nj < 50){
                            if(tmp[ni][nj] > 0 && tmp[ni][nj] < 100){
                                flag = true;
                            }
                        }
                    }
                    if(flag){
                        c[i][j]++;
                    }
                }
            }
        }
        //print(c);
        update_d(d, c);

        // road
        int i1 = s[o].i1;
        int i2 = s[o].i2;
        int j1 = s[o].j1;
        int j2 = s[o].j2;
        if(s[o].op == 0){
            int cost = 0;
            if(s[o].i1 == s[o].i2){
                cost = s[o].j2 - s[o].j1;
            }else{
                cost = s[o].i2 - s[o].i1;
            }
            if(cost*cost <= m){
                if(s[o].i1 == s[o].i2){
                    int i = s[o].i1;
                    inc(j, s[o].j1, s[o].j2+1){
                        if(c[i][j] == 100 || c[i][j] == 200) continue;
                        c[i][j] = 300;
                    }
                }else{
                    int j = s[o].j1;
                    inc(i, s[o].i1, s[o].i2+1){
                        if(c[i][j] == 100 || c[i][j] == 200) continue;
                        c[i][j] = 300;
                    }
                }
                m -= cost*cost;
            }
        }

        // plant
        if(s[o].op == 1){
            if(c[i1][j1] >= 0 && c[i1][j1] < 100){
                c[i1][j1]++;
            }
        }

        // harvest
        if(s[o].op == 2){
            inc(i, i1, i2+1){
                inc(j, j1, j2+1){
                    if(c[i][j] >= 0 && c[i][j] < 100){
                        if(w < d[i][j]-10) break;
                        w -= d[i][j]-10;
                        m += c[i][j];
                        t += c[i][j];
                        c[i][j] = 0;
                    }
                }
            }
        }

        // destroy
        if(s[o].op == 3){
            inc(i, i1, i2+1){
                inc(j, j1, j2+1){
                    if(c[i][j] == 200) continue;
                    if(c[i][j] == 0) continue;
                    if(m < d[i][j]) break;
                    m -= d[i][j];
                    c[i][j] = 0;
                }
            }
        }

        // growup
        if(s[o].op == 4){
            dec(a, 0, i1+1){
                if(a*a <= m){
                    w_max += a;
                    m -= a*a;
                    break;
                }
            }
        }

        // warpgate
        if(s[o].op == 5){
            if(c[i1][j1] != 100 && c[i1][j1] != 200 && m >= 1000){
                c[i1][j1] = 200;
                m -= 1000;
            }
        }

        // work
        if(s[o].op == 6){
            m++;
        }
    }

    //cout << t << " " << m << " " << w_max << endl;

    return t;
} // }}}

struct S {
    int ci, cj;
    int w;
    bool f;
};

struct MS {
    vector<S> s;
    int w; // 奇数

    vector<SEQ> get_seq(){
        vector<SEQ> seq;

        for(int i=0;i<1000;){
            // warpgate
            if(i%200 == 0){
                int ci = s[i/200].ci;
                int cj = s[i/200].cj;
                if(i == 0){
                    // road
                    seq.pb({0, cj, ci-2, cj, ci-1});
                    seq.pb({0, cj, ci+1, cj, ci+2});
                    seq.pb({0, cj-2, ci, cj-1, ci});
                    seq.pb({0, cj+1, ci, cj+2, ci});
                    i += 4;
                }else if(i == 200){
                    seq.pb({3, cj, ci, cj, ci});
                    seq.pb({5, cj, ci, 0, 0});

                    seq.pb({3, cj, ci-2, cj, ci-1});
                    seq.pb({0, cj, ci-2, cj, ci-1});
                    seq.pb({3, cj, ci+1, cj, ci+2});
                    seq.pb({0, cj, ci+1, cj, ci+2});
                    seq.pb({3, cj-2, ci, cj-1, ci});
                    seq.pb({0, cj-2, ci, cj-1, ci});
                    seq.pb({3, cj+1, ci, cj+2, ci});
                    seq.pb({0, cj+1, ci, cj+2, ci});


                    seq.pb({3, cj-2, ci-2, cj-1, ci-1});
                    seq.pb({3, cj+1, ci-2, cj+2, ci-1});
                    seq.pb({3, cj-2, ci+1, cj-1, ci+2});
                    seq.pb({3, cj+1, ci+2, cj+2, ci+2});

                    i += 14;
                }else{
                    seq.pb({3, cj, ci, cj, ci});
                    seq.pb({5, cj, ci, 0, 0});

                    seq.pb({3, cj-2, ci-1, cj+2, ci-1});
                    seq.pb({0, cj-2, ci-1, cj+2, ci-1});
                    seq.pb({3, cj-2, ci+1, cj+2, ci+1});
                    seq.pb({0, cj-2, ci+1, cj+2, ci+1});

                    seq.pb({3, cj-2, ci, cj+2, ci});
                    seq.pb({3, cj-2, ci-2, cj+2, ci-2});
                    seq.pb({3, cj-2, ci+2, cj+2, ci+2});
                    i += 4;
                }


                //seq.pb({0, cj-2, ci-3, cj-1, ci-3});
                //seq.pb({0, cj+1, ci-3, cj+2, ci-3});

                //seq.pb({0, cj-2, ci+3, cj-1, ci+3});
                //seq.pb({0, cj+1, ci+3, cj+2, ci+3});

                //seq.pb({0, cj+3, ci-2, cj+3, ci-1});
                //seq.pb({0, cj+3, ci+1, cj+3, ci+2});

                //seq.pb({0, cj-3, ci-2, cj-3, ci-1});
                //seq.pb({0, cj-3, ci+1, cj-3, ci+2});


                inc(k, 0, 4){
                    int ni = ci + di[k]*(w);
                    int nj = cj + dj[k]*(w);
                    if(ni >= 0 && ni < 50 && nj >= 0 && nj < 50){
                        s.pb({ni, nj, 2, false});
                        break;
                    }
                }
                continue;
            }

            // harvest
            bool flag = false;
            inc(k, 0, s.size()-1){
                if(i%30 == k){
                    seq.pb({2, s[k].cj-2, s[k].ci-2, s[k].cj+2, s[k].ci+2});
                    i++;
                    flag = true;
                    break;
                }
            }
            if(flag) continue;

            // plant
            flag = false;
            inc(k, 0, s.size()-1){
                if(i%(s.size()) == k){
                    seq.pb({1, s[k].cj-2+rnd()%w, s[k].ci-2+rnd()%w, 0, 0});
                    flag = true;
                    i++;
                    break;
                }
            }
            if(flag) continue;

            seq.pb({6, 0, 0, 0, 0});
            i++;
        }

        
        for(auto &se : seq){
            se.i1 = min(49, max(0, se.i1));
            se.i2 = min(49, max(0, se.i2));
            se.j1 = min(49, max(0, se.j1));
            se.j2 = min(49, max(0, se.j2));
        }

        return seq;
    }
};


int main() {
    clock_t start = clock();

    int si, sj;

    // input
    inc(i, 0, 50){
        cin >> A[i];
        inc(j, 0, 50){
            if(A[i][j] == 'W'){
                si = i;
                sj = j;
            }
        }
    }

    MS ms = MS{{}, 5};
    ms.s.pb({si, sj, 2, false});

    vector<SEQ> seq = ms.get_seq();
    //cout << eval(seq) << endl;


    // SeqA
    //Seq stat, next, best;
    //double tsec = 0;
    //double time = 0;
    //double temp = temperature(0);
    //double e, ne;

    //init(stat);
    //best = stat;
    //e = eval(stat);
    //for(int step=0;;step++){
        //if(step%INTERVAL == 0){
            //tsec = (double)(clock() - start)/CLOCKS_PER_SEC;
            //if(tsec > MAX_T){
                //break;
            //}
            //time = tsec/MAX_T;
            //temp = temperature(time);
            ////cout << step << " " << eval(best) << endl;
            //cout << e << endl;
        //}

        //if(ne > e){
            //stat = next;
            //e = ne;
        //}

        ////if(ne < e){
            ////if(stat.e < best.e){
                ////best = stat;
            ////}
        ////}else if(uniform() < prob(e, ne, temp)){
        ////}else{
        ////}

    //}

    ////// output
    output(seq);

    return 0;
}
