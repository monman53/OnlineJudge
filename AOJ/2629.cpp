// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    26
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    double d;cin >> d;
    if(EQ(d - double(int(d)), 0)){
        printf("%0.10lf\n", max(d+1, d*sqrt(2.0)));
    }else{ 
        if(d < sqrt(int(d)*int(d) + 1)){
            printf("%0.10lf\n", max(int(d)+1.0, d*sqrt(2.0)));
        }else{
            printf("%0.10lf\n", d*sqrt(2.0));
        }
    }
    return 0;
}
