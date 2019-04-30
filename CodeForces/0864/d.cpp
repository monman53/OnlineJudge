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
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> a(n);
    map<int, int> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
        m[a[i]]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1;i<=n;i++){
        if(m.find(i) == m.end()){
            pq.push(i);
        }
    }

    int count = 0;
    vector<int> ans(n);
    vector<bool> next(n+1, false);
    for(int i=0;i<n;i++){
        if(m[a[i]] == 1){
            ans[i] = a[i];
        }else{
            int top = pq.top();
            if(!next[a[i]]){
                if(a[i] < top){
                    next[a[i]] = true;
                    ans[i] = a[i];
                    continue;
                }
            }
            count++;
            ans[i] = top;
            pq.pop();
            m[a[i]]--;
        }
    }
    cout << count << endl;
    for(int i=0;i<n;i++){
        cout << ans[i];
        if(i != n-1){
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
