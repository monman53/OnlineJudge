#include <bits/stdc++.h>
using namespace std;

int L;

string rec2(string a, string b, char l, char r, int i) {
    if(i == L) return "YES";
    if(a[i] == b[i]){
        return rec2(a, b, l, r, i+1);
    }else{
        return a[i] == r && b[i] == l ? "NO" : "YES";
    }
}

string rec1(string a, string b, string c, int i) {
    if(i == L) return "YES";
    if(a[i] == b[i] && b[i] == c[i]) return rec1(a, b, c, i+1);
    if(a[i] == c[i]) return "NO";
    if(a[i] == b[i]) return rec2(a, b, b[i], c[i], i+1);
    if(b[i] == c[i]) return rec2(b, c, a[i], b[i], i+1);
    return "YES";
}

string solve() {
    cin >> L;
    string a, b, c;cin >> a >> b >> c;
    return rec1(b, a, c, 0) + " " + rec1(c, b, a, 0) + " " + rec1(a, c, b, 0);
}

int main() {
    int t;cin >> t;
    for(int i=0;i<t;i++){
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
    return 0;
}
