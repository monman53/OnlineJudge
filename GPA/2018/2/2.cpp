#include <bits/stdc++.h>
using namespace std;

int main() {
    int m[10] = {10000, 5000, 2000, 1000, 500, 100, 50, 10, 5, 1};
    int mmax[4] = {1000, 500, 400, 300};
    int n = 13754002;
    for(int i=0;i<4;i++){
        int k = min(n/m[i], mmax[i]);
        cout << m[i] << " " << k << endl;
        n -= k*m[i];
    }
    for(int i=4;i<10;i++){
        int k = n/m[i];
        cout << m[i] << " " << k << endl;
        n -= k*m[i];
    }
    return 0;
}
