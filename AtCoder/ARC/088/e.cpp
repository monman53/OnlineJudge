// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

// Binary Indexed Tree // {{{
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

// 順列の転倒数 (1-indexed)
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
// }}}

// 文字列sは並び替えて回文にできるか
// ARC088E
bool palindromable(string s) {
    map<char, int> m;
    for(auto c : s){
        m[c]++;
    }
    int ocnt = 0;
    for(auto kv : m){
        if(kv.second%2 == 1) ocnt++;
    }
    return ocnt < 2;
}

// 隣り合う文字をswapすることを繰り返して
// 文字列sを文字列tにするswapの最小回数
// (必ずsをtにできると仮定する)
// ARC088E
LL nSwapST(string s, string t) {
    map<char, vector<int>> pos;
    map<char, int> cnt;
    vector<int> p; // 順列
    int n = s.size();
    for(int i=0;i<n;i++){
        pos[s[i]].push_back(i+1);
    }
    for(int i=0;i<n;i++){
        p.push_back(pos[t[i]][cnt[t[i]]++]);
    }
    return inv(p); // 順列の転倒数
}

int main() {
    std::ios::sync_with_stdio(false);
    string s;cin >> s;
    int n = s.size();

    // そもそも回文にできない
    if(!palindromable(s)){
        cout << -1 << endl;
        return 0;
    }

    // 左右に分ける
    map<char, int> sum, cnt;
    for(auto c : s) sum[c]++;
    string sl = "";
    string sc = "";
    for(int i=0;i<n;i++){
        char c = s[i];
        cnt[c]++;
        if(cnt[c] <= sum[c]/2){
            sl += c;
        }else if(cnt[c] == (sum[c]+1)/2){
            sc += c;
        }
    }

    // 右を左の逆と同じにする
    string sr = sl;
    reverse(sr.begin(), sr.end());

    cout << nSwapST(s, sl+sc+sr) << endl;

    return 0;
}
