// includes, macros {{{
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <functional>
#include <numeric>
#include <limits>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
 
typedef long long ll;
typedef unsigned long long ull; // }}}

struct Edge{
    ull p, c;
    ull w;
};

vector<Edge> v;


ull find_parent(ull a, ull b){
    set<ull> bs;
    while(b > 0){
        bs.insert(b);
        b/=2;
    }
    while(a > 0){
        if(bs.end() != bs.find(a)){
            return a;
        }
        a/=2;
    }
}

void add(ull p, ull c, ull w){
    while(p > c){
        bool flag = true;
        for(int i=0;i<int(v.size());i++){
            if(v[i].p == p && v[i].c == p/2){
                // cout << "add " << p << " " << p/2 << " " << w << endl;
                v[i].w += w;
                flag = false;
                break;
            }
        }
        if(flag){
            Edge e;
            e.p = p;
            e.c = p/2;
            e.w = w;
            // cout << "new " << p << " " << p/2 << " " << w << endl;
            v.push_back(e);
        }
        p/=2;
    }
}

ull sum(ull p, ull c){
    ull ret = 0;
    while(p > c){
        for(int i=0;i<int(v.size());i++){
            if(v[i].p == p && v[i].c == p/2){
                ret += v[i].w;
                break;
            }
        }
        p/=2;
    }
    return ret;
}

int main(){
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int t;
        ull v, u, w;
        cin >> t;
        if(t == 1){
            cin >> v >> u >> w;
            ull c = find_parent(v, u);
            // cout << v << " " << u << " " << w << " " << c <<  endl;
            add(v, c, w);
            add(u, c, w);
        }else{
            cin >> v >> u;
            ull c = find_parent(v, u);
            // cout << "#" << sum(v, c) << endl;
            cout << sum(v, c) + sum(u, c) << endl;
        }
    }
    return 0;
}
