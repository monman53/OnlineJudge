// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

struct D {
    int a, b, c;
};

struct Point {
    double x, y;
};

vector<double> px;
vector<double> py;

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<D> d(n);
    for(int i=0;i<n;i++){
        int a, b, c;cin >> a >> b >> c;
        d[i] = {a, b, c};
    }
    vector<Point> p;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double y = double(d[i].a*d[j].c-d[j].a*d[i].c)/double(d[i].a*d[j].b-d[j].a*d[i].b);
            double x = double(d[i].c-d[i].b*y)/double(d[i].a);
            px.push_back(x);
            py.push_back(y);
        }
    }
    int m = p.size();

    // x
    sort(px.begin(), px.end());
    double maxx = 0;
    for(int i=0;i<m;i++){
        maxx += px[i] - px[0];
    }
    double nowx = maxx;
    double ansx = px[0];
    for(int i=1;i<m;i++){
        double dx = px[i] - px[i-1];
        nowx += dx*i - dx*(m-i);
        if(nowx < maxx){
            maxx = nowx;
            ansx = px[i];
        }
    }

    // y
    sort(py.begin(), py.end());
    double maxy = 0;
    for(int i=0;i<m;i++){
        maxy += py[i] - py[0];
    }
    double nowy = maxy;
    double ansy = p[0].y;
    for(int i=1;i<m;i++){
        double dy = py[i] - py[i-1];
        nowy += dy*i - dy*(m-i);
        if(nowy < maxy){
            maxy = nowy;
            ansy = py[i];
        }
    }
    printf("%0.10lf %0.10lf\n", ansx, ansy);
    return 0;
}
