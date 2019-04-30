#include <bits/stdc++.h>
using namespace std;

int k;
int d[100];

int solve() {
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> d[i];
    }

    vector<int> v(k);
    for(int i=0;i<k;i++){
        v[i] = k-i-1;
    }

    do{
        for(int i=0;i<k;i++){
            printf("%d ", v[i]);
        }
        printf("\n");
    }while(prev_permutation(v.begin(), v.end()));
    return 0;
}

int main() {
    int t;cin >> t;
    for(int i=0;i<t;i++){
        printf("Case #%d: %d\n", i+1, solve());
    }
    return 0;
}
