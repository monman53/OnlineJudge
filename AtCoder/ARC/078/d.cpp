// header {{{
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <stack>
// #include <tuple>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define ALPHABET    (26)
#define EPS         (1e-10)
#define INF         (1000000005LL)
#define MOD         (1000000007LL)
// #define EQ(a, b)    (abs((a)-(b)) < EPS)
inline bool EQ(double a, double b) {return abs(a-b) < EPS;}
// ciling(x/y) = (x+y-1)/y

// template<class T>
// using P = pair<T, T>;
using ll  = long long;
using ull = unsigned long long;
// }}}

vector<int> e[100000];
bool visited[2][100000];
int dst[2][100000];
// int ans = -1;
//
void dfs(int n, int i, int cost){
    visited[n][i] = true;
    dst[n][i] = cost;
    for(auto next : e[i]){
        if(!visited[n][next]){
            dfs(n, next, cost+1);
        }
    }
}
//
typedef pair<int, int> P;


int main() {
    int n;cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b;cin >> a >> b;
        a--;b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    for(int i=0;i<n;i++){
        visited[0][i] = false;
        visited[1][i] = false;
    }

    dfs(0, 0, 0);
    dfs(1, n-1, 0);

    // for(int i=0;i<n;i++){
    //     dst[0][i] = INF;
    //     dst[1][i] = INF;
    // }
    // int fennec = dfs(0);
    // for(int i=0;i<n;i++) visited[i] = false;
    // int snuke = dfs(n-1);

    // for(int i=0;i<2;i++){
    //     queue<P> q;
    //     if(i == 0){
    //         q.push({0, 0});
    //     }else{
    //         q.push({0, n-1});
    //     }
    //     while(!q.empty()){
    //         auto cv = q.front();q.pop();
    //         int cid = cv.second;
    //         int ccost = cv.first;
    //
    //     }
    // }

    int count = 0;
    for(int i=0;i<n;i++){
        // cout << dst[0][i] << " " << dst[1][i] << endl;
        if(dst[0][i] <= dst[1][i]){
            count++;
        }
    }

    if(count > n/2){
        cout << "Fennec" << endl;
    }else{
        cout << "Snuke" << endl;
    }
    return 0;
}
