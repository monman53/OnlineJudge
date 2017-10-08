// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using PII   = pair<int, int>;
using LL  = long long;
template<class T>
using PTI = pair<T, int>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}


int main() {
    std::ios::sync_with_stdio(false);

    int n;cin >> n;
    vector<vector<int>> g(n);

    int ans = 0;
    g.resize(n);
    queue<PII> q;
    set<PII> s;

    int m;cin >> m;
    for(int i=0;i<m;i++){
        int a, b;cin >> a >> b;a--;b--;
        if(a > b) swap(a, b);
        g[a].push_back(b);
        g[b].push_back(a);
        q.push({a, b});
        s.insert({a, b});
    }


    while(!q.empty()){
        auto v = q.front();
        q.pop();
        int a = v.first;
        int b = v.second;
        for(auto aa : g[a]){
            for(auto bb : g[b]){
                int aaa = aa;
                int bbb = bb;
                if(aaa > bbb) swap(aaa, bbb);
                if(aaa != bbb && s.find({aaa, bbb}) == s.end()){
                    s.insert({aaa, bbb});
                    q.push({aaa, bbb});
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
