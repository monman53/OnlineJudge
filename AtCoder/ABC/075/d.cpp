// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, K;cin >> n >> K;
    vector<int> x(n), y(n);
    vector<int> xs, ys;
    map<int, int> mxm, mym;
    map<int, int> mx, my;
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    xs = x;ys = y;
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    int xx = 0;
    int yy = 0;
    mx[xs[0]] = 0;
    my[ys[0]] = 0;
    for(int i=1;i<n;i++){
        if(xs[i] != xs[i-1]) xx++;
        mx[xs[i]] = xx;
        if(ys[i] != ys[i-1]) yy++;
        my[ys[i]] = yy;
    }
    bool c[50][50];
    memset(c, false, sizeof(c));
    for(int i=0;i<n;i++){
        c[my[y[i]]][mx[x[i]]] = 1;
    }
    int h = yy + 1;
    int w = xx + 1;
    int sum[51][51];
    for(int i=0;i<=h;i++){
        for(int j=0;j<=w;j++){
            sum[i][j] = 0;
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            sum[i+1][j+1] = c[i][j] + sum[i][j+1] + sum[i+1][j] - sum[i][j];
        }
    }
    vector<LL> ans;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            for(int k=0;k<=i;k++){
                for(int l=0;l<=j;l++){
                    if(sum[i+1][j+1] - sum[i+1][l] - sum[k][j+1] + sum[k][l] >= K){
                        int yi = ys[i];
                        int xj = xs[j];
                        int yk = ys[k];
                        int xl = xs[l];
                        //cout << xi << " " << yj << " " << xk << " " << yl << endl;
                        ans.push_back(LL(xj-xl)*LL(yi-yk));
                    }
                }
            }
        }
    }
    cout << *min_element(ans.begin(), ans.end()) << endl;
    return 0;
}
