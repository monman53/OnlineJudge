// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

// うるう年判定
// ARC002B
bool isUruu(int y) {
    return (y%4 == 0 && y%100 != 0) || y%400 == 0;
}

// 西暦y年のm月は何日あるか
// ARC002B
int month(int y, int m) {
    if(m ==  1) return 31;
    if(m ==  2) return 28 + (isUruu(y) ? 1 : 0);
    if(m ==  3) return 31;
    if(m ==  4) return 30;
    if(m ==  5) return 31;
    if(m ==  6) return 30;
    if(m ==  7) return 31;
    if(m ==  8) return 31;
    if(m ==  9) return 30;
    if(m == 10) return 31;
    if(m == 11) return 30;
    if(m == 12) return 31;
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    string s;cin >> s;
    int Y = stoi(s.substr(0, 4));
    int M = stoi(s.substr(5, 2));
    int D = stoi(s.substr(8, 2));
    for(int d=D;d<=month(Y, M);d++){
        if(Y%M == 0 && Y/M%d == 0){
            printf("%04d/%02d/%02d\n", Y, M, d);
            return 0;
        }
    }
    for(int m=M+1;m<=12;m++){
        for(int d=1;d<=month(Y, m);d++){
            if(Y%m == 0 && Y/m%d == 0){
                printf("%04d/%02d/%02d\n", Y, m, d);
                return 0;
            }
        }
    }
    printf("%04d/%02d/%02d\n", ++Y, 1, 1);
    return 0;
}
