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
#define CILING(a, b)    (((a)+(b)-1LL)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}

struct Data {
    string l;
    int n;
    string r;
};

Data parse(string s){
    int n = s.size();
    int p, q;
    int b = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '(') b++;
        if(s[i] == ')') b--; 
        if(b == 0){
            p = i;
            break;
        }
    }
    b = 0;
    for(int i=n-1;i>=0;i--){
        if(s[i] == '(') b++;
        if(s[i] == ')') b--; 
        if(b == 0){
            q = i;
            break;
        }
    }

    string ls = s.substr(1, p-1);
    string ns = s.substr(p+2, q-1-(p+2));
    string rs = s.substr(q+1, n-1-(q+1));

    return {ls, stoi(ns), rs};
}

string solve(string a, string b){
    if(a == "" || b == "") return "";
    Data da = parse(a);
    Data db = parse(b);
    string ls = solve(da.l, db.l);
    string ns = to_string(da.n+db.n);
    string rs = solve(da.r, db.r);
    return "(" + ls + ")" + "[" + ns + "]" + "(" + rs + ")";
}

int main() {
    string a, b;cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}
