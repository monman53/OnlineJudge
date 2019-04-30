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
    map<char, bool> m;
    string s;cin >> s;
    for(char c='a';c<='z';c++){
        m[c] = false;
    }
    for(auto c : s) m[c] = true;
    cin >> s;
    int ns = s.size();
    int n;cin >> n;
    for(int i=0;i<n;i++){
        string qs;cin >> qs;
        int nqs = qs.size();
        if((int)qs.size() < (int)s.size()-1){
            cout << "NO" << endl;
            continue;
        }

        string ss = "";
        for(int j=0;j<ns;j++){
            if(s[j] == '*'){
                for(int k=0;k<=nqs-ns;k++){
                    ss += '*';
                }
            }else{
                ss += s[j];
            }
        }
        int nss = ss.size();

        if(nss != nqs){
            cout << "NO" << endl;
            continue;
        }

        bool flag = true;
        for(int j=0;j<nss;j++){
            switch(ss[j]){
                case '?':
                    if(!m[qs[j]]){
                        flag = false;
                    }
                    break;
                case '*':
                    if(m[qs[j]]){
                        flag = false;
                    }
                    break;
                default:
                    if(qs[j] != ss[j]){
                        flag = false;
                    }
            }
        }

        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
