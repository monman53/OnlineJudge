// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

vector<vector<int>> g;
vector<bool> visited;
deque<int> ans;
bool flag = true;

void solve(int to) {
    if(flag){
        ans.push_front(to);
    }else{
        ans.push_back(to);
    }
    visited[to] = true;
    for(auto next : g[to]){
        if(!visited[next]){
            solve(next);
            break;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    g.resize(n);
    visited.resize(n, false);
    inc(i, 0, m){
        int a, b;cin >> a >> b;a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    visited[0] = true;
    visited[g[0][0]] = true;
    solve(0);
    flag = false;
    solve(g[0][0]);

    cout << ans.size() << endl;
    bool f = true;
    for(auto a : ans){
        if(f){
            f = false;
        }else{
            cout << " ";
        }
        cout << a+1;
    }
    return 0;
}
