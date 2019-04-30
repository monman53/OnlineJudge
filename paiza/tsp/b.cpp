// header {{{
// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)
#define CILING(a, b)    (((a)+(b)-1LL)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}
// 2d geometry {{{

typedef complex<double> P;
typedef vector<P> PL;

namespace std {
    bool  operator < (P a, P b) {
        // return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
        return imag(a) != imag(b) ? imag(a) < imag(b) : real(a) < real(b);
    }
}

// 長さ
// double length = abs(a);

// 偏角
// double theta = arg(a);

// 単位ベクトル
// P n = a/abs(a);

// 法線ベクトル
// P n1 = a*P(0, 1);
// P n2 = a*P(0, -1);

// ヘロンの公式
double heron(double a, double b, double c) {
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

// 内積
double dot(P a, P b) {
    return a.real()*b.real() + a.imag()*b.imag();
}

// 外積
double cross(P a, P b) {
    return a.real()*b.imag() - a.imag()*b.real();
}

// verified AOJ CGL_1_C
int ccw(P a, P b, P c) {
    b = b - a;
    c = c - a;
    if(cross(b, c) > EPS) return +1; // counter clockwise
    if(cross(b, c) <-EPS) return -1; // clockwise
    if(dot(b, c) < 0)     return +2; // cab (back)
    if(abs(b) < abs(c))   return -2; // abc (front)
    return 0;                        // acb (on segment)
}

// 直交判定
// verified AOJ CGL_2_A
bool isOrthogonalLL(P a1, P a2, P b1, P b2) {
    return EQ(dot(a1-a2, b1-b2), 0.0);
}

// 平行判定
// verified AOJ CGL_2_A
bool isParallelLL(P a1, P a2, P b1, P b2) {
    return EQ(cross(a1-a2, b1-b2), 0.0);
}

// 線分と線分の交差判定
// verified AOJ CGL_2_B
bool isIntersectedSS(P a1, P a2, P b1, P b2) {
    return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
           ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

// }}}
// Union-Find {{{
// verified AOJ DSL_1_A
struct UF {
    vector<int> p;  // parent
    vector<int> r;  // rank

    UF(int n) {
        p.resize(n);
        r.resize(n);
        for(int i=0;i<n;i++){
            p[i] = i;
            r[i] = 1;
        }
    }

    int find(int x) {
        if(x == p[x]){
            return x;
        }else{
            return p[x] = find(p[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(r[x] < r[y]){
            p[x] = y;
        }else{
            p[y] = x;
            if(r[x] == r[y]){
                r[x]++;
            }
        }
    }
}; // }}}

#define L 9

struct Data {
    int x, y;
};

struct E {
    int s, t;
    double w;
};

int n;
vector<int> grid[L][L][L][L][L][L];
vector<Data> p;
vector<E> e;
vector<vector<int>> g;

void dfs(vector<int> &ans, int s, int t){
    ans.push_back(t);
    for(auto n : g[t]){
        if(n != s){
            dfs(ans, t, n);
        }
    }
}

double dist(const vector<int> &v) {
    double ret = 0;
    for(int i=1;i<n;i++){
        double dx = p[v[i]].x - p[v[i-1]].x;
        double dy = p[v[i]].y - p[v[i-1]].y;
        ret += sqrt(dx*dx + dy*dy);
    }
    return ret;
}

void print(const vector<int> &v) {
    for(int i=0;i<n;i++){
        int x = p[v[i]].x;
        int y = p[v[i]].y;
        cout << x << " " << y << endl;
    }
}

void remove_cross(vector<int> &v) {
    while(true){
        bool flag = false;
        for(int i=1;i<n;i++){
            double s1x = p[v[i-1]].x;
            double s1y = p[v[i-1]].y;
            double t1x = p[v[i]].x;
            double t1y = p[v[i]].y;
            for(int j=i+2;j<n;j++){
                double s2x = p[v[j-1]].x;
                double s2y = p[v[j-1]].y;
                double t2x = p[v[j]].x;
                double t2y = p[v[j]].y;
                if(isIntersectedSS({s1x, s1y}, {t1x, t1y},
                            {s2x, s2y}, {t2x, t2y})){
                    swap(v[i], v[j-1]);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) break;
    }
}

int main() {
    cin >> n;
    vector<int> ans;
    for(int i=0;i<n;i++){
        int x, y;cin >> x >> y;
        p.push_back({x, y});
        ans.push_back(i);
    }

    sort(p.begin(), p.end(), [](Data p1, Data p2){
            return p1.x < p2.x;
            });

    //
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double dx = p[i].x - p[j].x;
            double dy = p[i].y - p[j].y;
            e.push_back({i, j, sqrt(dx*dx+dy*dy)});
        }
    }
    sort(e.begin(), e.end(), [](E e1, E e2){
            return e1.w < e2.w;});


    vector<int> v;
    map<int, int> m;
    for(int i=0;i<n*n;i++){
        m[i] = 1;
    }
    for(int i=0;i<2000;i++){
        g.clear();
        g.resize(n);
        UF uf(n);
        v.clear();
        int count = 0;
        vector<int> skip;
        for(int j=0;j<int(e.size());j++){
            if(i>4){
                if(rand()%i < m[j]){
                    skip.push_back(j);
                    continue;
                }
            }
            auto ee = e[j];
            if(uf.find(ee.s) != uf.find(ee.t) &&
               g[ee.s].size() < 2 && g[ee.t].size() < 2){
                uf.unite(ee.s, ee.t);
                g[ee.s].push_back(ee.t);
                g[ee.t].push_back(ee.s);
                count++;
            }
            if(count == n-1) break;
        }
        for(int i=0;i<n;i++){
            if(g[i].size() == 1){
                dfs(v, -1, i);
                break;
            }
        }
        if(v.size() != n) continue;
        remove_cross(v);
        if(dist(v) < dist(ans)){
            for(auto id : skip){
                m[id]++;
            }
            ans = v;
        }
    }

    print(ans);

    return 0;
}
