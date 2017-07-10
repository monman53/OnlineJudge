// header {{{
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    26
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
#define INF         1000000005

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &aa : a){
        cin >> aa;
    }
    vector<int> ans;
    for(int i=-100;i<=100;i++){
        int sum = 0;
        for(auto aa : a){
            sum += (aa-i)*(aa-i);
        }
        ans.push_back(sum);
    }
    cout << *min_element(ans.begin(), ans.end()) << endl;
    return 0;
}
