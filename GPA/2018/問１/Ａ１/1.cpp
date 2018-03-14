#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, a, b;
    cin >> s;

    set<string> sset;

    int ans = 0;
    cout << s << endl;
    while(true){
        a = s;

        b = s;
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        sort(b.begin(), b.end());

        int aa = stoi(a);
        int bb = stoi(b);

        //cout << aa << " " << bb << endl;

        s = to_string(aa-bb);
        if(sset.find(s) != sset.end()){
            break;
        }
        cout << s << endl;
        sset.insert(s);
    }
    cout << s << endl;
    return 0;
}
