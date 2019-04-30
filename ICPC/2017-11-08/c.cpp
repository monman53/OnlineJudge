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
        int n, m;cin >> n >> m;
        if(n == 0) break;

        UF uf(n);

        vector<pair<int, pair<int, int>>> e;

        for(int i=0;i<m;i++){
            int s, t, c;cin >> s >> t >> c;s--;t--;
            e.push_back({c, {s, t}});
        }

        sort(e.begin(), e.end());

        int ans = 0;
        int count = 0;

        for(int i=0;i<m;i++){
            int s = e[i].second.first;
            int t = e[i].second.second;
            int c = e[i].first;
            if(uf.find(s) != uf.find(t)){
                if(count == (n-1)/2){
                    ans = c;
                }
                count++;
                uf.unite(s, t);
            }
        }

        cout << ans << endl;
    }
    return 0;
}
