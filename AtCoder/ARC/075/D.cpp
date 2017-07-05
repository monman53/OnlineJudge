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
    int n, a, b;cin >> n >> a >> b;
    priority_queue<int> pq;
    vector<int> hs;
    int s = a + (n-1)*b;
    int mmin = 1000000005;
    for(int i=0;i<n;i++){
        int h;cin >> h;
        hs.push_back(h);
        mmin = min(mmin/)
    }
    for(int i=0;i<n;i++){
        int h;cin >> h;
        hs.push_back(h);
    }




    int count = 0;
    while(!pq.empty()){
        int ch = pq.top();
        pq.pop();
        if(ch - count*b <= 0){
            continue;
        }
        int nh = ch - a + b;
        count+=cc;
        if(nh > 0){
            pq.push(nh);
        }
    }

    cout << count << endl;
    return 0;
}
