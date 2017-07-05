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
    int n;cin >> n;
    vector<int> mmin(ALPHABET, 100);
    for(int i=0;i<n;i++){
        string s;cin >> s;
        vector<int> counter(ALPHABET, 0);
        for(auto c : s){
            counter[c-'a']++;
        }
        for(int i=0;i<ALPHABET;i++){
            mmin[i] = min(mmin[i], counter[i]);
        }
    }
    for(int i=0;i<ALPHABET;i++){
        char c = 'a'+i;
        for(int j=0;j<mmin[i];j++){
            cout << c;
        }
    }
    cout << endl;
    return 0;
}
