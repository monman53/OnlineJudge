// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

// Binary Indexed Tree
struct BIT {
    vector<int> bit;
    int n;
    BIT(int n) {
        bit.resize(n+1, 0);
        this->n = n;
    }
    int sum(int i) {
        int s = 0;
        while(i > 0){
            s += bit[i];
            // i & -i はiの最後の1のビット
            i -= i & -i;
        }
        return s;
    }
    void add(int i, int x) {
        while(i <= n){
            bit[i] += x;
            i += i & -i;
        }
    }
};

// 転倒数 (1-indexed)
LL inv(vector<int> a) {
    int n = a.size();
    BIT bit(n);
    LL ans = 0;
    for(int j=0;j<n;j++){
        ans += j - bit.sum(a[j]);
        bit.add(a[j], 1);
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    cout << inv(a) << endl;
    return 0;
}
