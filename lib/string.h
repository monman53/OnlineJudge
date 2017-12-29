// {{{
// 文字列sの文字cによるsplit
// ABC033
vector<string> split(string &s, char c) {
    vector<string> ret;
    int b = 0;
    int n = s.size();
    int i;
    for(i=0;i<n;i++){
        if(s[i] == c){
            ret.push_back(s.substr(b, i-b));
            b = i+1;
        }
    }
    ret.push_back(s.substr(b, i-b));
    return ret;
}
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
// }}}
