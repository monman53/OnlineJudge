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
#define CILING(a, b)    (((a)+(b)-1)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}

int main() {
    int n, m;cin >> n >> m;
    queue<int> q[300];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;cin >> a;
            q[i].push(a);
        }
    }
    map<int, bool> dont;
    int ans = 40000;
    while(true){
        map<int, int> m;
        for(int i=0;i<n;i++){
            if(q[i].empty()){
                goto end;
            }
            while(dont[q[i].front()]){
                q[i].pop();
                if(q[i].empty()){
                    goto end;
                }
            }
            m[q[i].front()]++;
        }
        int maxk = 0;
        int maxv = 0;
        for(auto kv : m){
            if(kv.second > maxv){
                maxv = kv.second;
                maxk = kv.first;
            }
        }
        ans = min(ans, maxv);

        dont[maxk] = true;

        map<int, int> m2;
        for(int i=0;i<n;i++){
            if(q[i].empty()){
                goto end;
            }
            while(dont[q[i].front()]){
                q[i].pop();
                if(q[i].empty()){
                    goto end;
                }
            }
            m2[q[i].front()]++;
        }
        maxk = 0;
        maxv = 0;
        for(auto kv : m2){
            if(kv.second > maxv){
                maxv = kv.second;
                maxk = kv.first;
            }
        }
        ans = min(ans, maxv);
    }
end:

    cout << ans << endl;
    return 0;
}
