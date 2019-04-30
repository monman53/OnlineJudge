#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int x;cin >> x;
    int k;cin >> k;
    vector<int> r, a, b, c;
    r.push_back(0);
    a.push_back(0);
    b.push_back(x);
    c.push_back(0);
    for(int i=0;i<k;i++){
        int rr;cin >> rr;
        int d = rr-r[i];
        int aa, bb, cc;
        if(i%2 == 0){
            aa = min(b[i], a[i] + max(0, 0-(c[i]-d)));
            bb = b[i];
            cc = max(0, c[i]-d);
        }else{
            aa = a[i];
            bb = max(a[i], b[i] - max(0, c[i]+(b[i]-a[i])+d-x));
            cc = min(x, c[i]+d);
        }
        r.push_back(rr);
        a.push_back(aa);
        b.push_back(bb);
        c.push_back(cc);
    }
    int q;cin >> q;
    for(int i=0;i<q;i++){
        int t, aa;cin >> t >> aa;
        int j = int(upper_bound(r.begin(), r.end(), t) - r.begin()) - 1;
        int d = t-r[j];
        int f;
        if(aa <= a[j]){
            f = c[j];
        }else if(aa <= b[j]){
            f = c[j] + (aa - a[j]);
        }else{
            f = c[j] + (b[j]-a[j]);
        }
        if(j%2 == 0){
            cout << max(0, f-d) << endl;
        }else{
            cout << min(x, f+d) << endl;
        }
    }
    return 0;
}
