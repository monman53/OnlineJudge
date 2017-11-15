#include <bits/stdc++.h>
using namespace std;

struct UF {
    vector<int> p;

    UF(int n) {
        p.resize(n);
        for(int i=0;i<n;i++){
            p[i] = i;
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
        p[y] = p[x];
    }
};

int main() {
    while(true){
        int n;cin >> n;
        if(n == 0) break;
        UF uf(n);

        vector<double> x(n), y(n), z(n), r(n);
        for(int i=0;i<n;i++){
            cin >> x[i] >> y[i] >> z[i] >> r[i];
        }

        vector<pair<double, pair<int, int>>> e;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double dx = x[i]-x[j];
                double dy = y[i]-y[j];
                double dz = z[i]-z[j];
                e.push_back({max(0.0, sqrt(dx*dx+dy*dy+dz*dz)-r[i]-r[j]), {i, j}});
            }
        }

        sort(e.begin(), e.end());

        double ans = 0;
        for(int i=0;i<(int)e.size();i++){
            int x = e[i].second.first;
            int y = e[i].second.second;
            double d = e[i].first;
            if(uf.find(x) != uf.find(y)){
                ans += d;
                uf.unite(x, y);
            }
        }

        printf("%.3lf\n", ans);
    }
    return 0;
}
