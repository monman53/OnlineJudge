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
    for(int i=0;i<n;i++){
        int x, y;cin >> x >> y;
        p.push_back({x, y});
    }

    sort(p.begin(), p.end(), [](Data p1, Data p2){
            return p1.x < p2.x;
            });

    // MST
    vector<int> ans_mst;
    g.resize(n);
    UF uf(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double dx = p[i].x - p[j].x;
            double dy = p[i].y - p[j].y;
            e.push_back({i, j, sqrt(dx*dx+dy*dy)});
        }
    }
    sort(e.begin(), e.end(), [](E e1, E e2){
            return e1.w < e2.w;});
    for(auto ee : e){
        if(uf.find(ee.s) != uf.find(ee.t)){
            uf.unite(ee.s, ee.t);
            g[ee.s].push_back(ee.t);
            g[ee.t].push_back(ee.s);
        }
    }
    dfs(ans_mst, -1, 0);
    remove_cross(ans_mst);
    for(int i=0;i<n;i++){
        vector<int> v = {};
        dfs(v, -1, i);
        remove_cross(v);
        if(dist(v) < dist(ans_mst)){
            ans_mst = v;
        }
    }

    // grid
    vector<int> ans_grid;
    int e1 = 1000000/L;
    int e2 = e1/L;
    int e3 = e2/L;
    for(int i=0;i<n;i++){
        int x = p[i].x;
        int y = p[i].y;
        x--;y--;
        int x1 = x/e1;
        int y1 = y/e1;
        int x2 = x%e1/e2;
        int y2 = y%e1/e2;
        int x3 = x%e1%e2/e3;
        int y3 = y%e1%e2/e3;
        grid[x1][y1][x2][y2][x3][y3].push_back(i);
    }
    for(int i=0;i<L*L;i++){
        int x1 = i/L;
        int y1 = (x1%2 == 0 ? i%L : L-1-i%L);
        for(int j=0;j<L*L;j++){
            int x2 = (y1%2 ? L-1-j/L : j/L);
            int y2 = ((x2%2) ^ (x1%2) ? L-1-j%L : j%L);
            for(int k=0;k<L*L;k++){
                int x3 = ((y1%2) ^ (y2%2) ? L-1-k/L : k/L);
                int y3 = ((x1%2) ^ (x2%2) ^ (x3%2) ? L-1-k%L : k%L);
                vector<int> &ps = grid[x1][y1][x2][y2][x3][y3];

                if(((x1%2) ^ (x2%2) ^ (x3%2)) != 0){
                    reverse(ps.begin(),
                            ps.end());
                }

                for(auto id : ps){
                    ans_grid.push_back(id);
                }
            }
        }
    }
    remove_cross(ans_grid);

    if(dist(ans_mst) < dist(ans_grid)){
        print(ans_mst);
    }else{
        print(ans_grid);
    }

    return 0;
}
