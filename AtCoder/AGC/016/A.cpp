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
    vector<int> gap(ALPHABET, 0);
    vector<int> gapmax(ALPHABET, 0);
    string s;cin >> s;
    for(int i=0;i<int(s.size());i++){
        char c = s[i];
        for(int j=0;j<ALPHABET;j++){
            if(j == c-'a'){
                gapmax[j] = max(gapmax[j], gap[j]);
                gap[j] = 0;
            }else{
                gap[j]++;
                if(i == int(s.size())-1){
                    gapmax[j] = max(gapmax[j], gap[j]);
                }
            }
        }
    }
    cout << *min_element(gapmax.begin(), gapmax.end()) << endl;
    return 0;
}
