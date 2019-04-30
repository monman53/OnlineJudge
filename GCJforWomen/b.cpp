#include <bits/stdc++.h>
using namespace std;

int l;
long long n[1000];
long long e[1000];

long long solve() {
    cin >> l;
    for(int i=0;i<l;i++){
        cin >> n[i] >> e[i];
    }
    long long c = n[0];
    for(int i=1;i<l;i++){
        c = n[i] + max(0LL, c - n[i]*e[i]);
    }
    return max(c, e[l-1]+1);
}

int main() {
    int t;cin >> t;
    for(int i=0;i<t;i++){
        printf("Case #%d: %lld\n", i+1, solve());
    }
    return 0;
}
