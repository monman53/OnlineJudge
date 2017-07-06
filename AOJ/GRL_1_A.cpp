// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define ALPHABET    26
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
#define INF         1000000005
// }}}

struct V {
    int cost;
    vector<pair<int, int>> ne;
};

typedef pair<int, int> P;

int main() {
    int n, m, r;cin >> n >> m >> r;
    vector<V> v(n, {INF, {}});
    for(int i=0;i<m;i++){       
        int s, t, d;cin >> s >> t >> d;
        v[s].ne.push_back({t, d});
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, r});
    while(!pq.empty()){
        auto cp = pq.top(); pq.pop();
        int ccost = cp.first;
        int cid = cp.second;

        if(v[cid].cost <= ccost){
            continue;
        }

        v[cid].cost = ccost;

        for(auto np : v[cid].ne){
            int nid = np.first;
            int ncost = ccost + np.second;
            pq.push({ncost, nid});
        }
    }

    for(auto vv : v){
        if(vv.cost == INF){
            cout << "INF" << endl;
        }else{
            cout << vv.cost << endl;
        }
    }
    return 0;
}
