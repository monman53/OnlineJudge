// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <deque>
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
    int dup = 0;
    deque<int> dq;
    map<int, int> m;

    for(int i=0;i<n;i++){
        int a;cin >> a;
        dq.push_back(a);
        if(m.find(a) == m.end()){
            m[a] = 0;
        }
        if(++m[a] == 2){
            dup++;
        }
    }

    while(true){
        int a = dq.front();
        dq.pop_front();
        int b = dq.front();
        dq.pop_front();
        int c = dq.front();
        dq.pop_front();

        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());

        if(--m[v[0]] == 1){
            dup--;
        }
        if(--m[v[2]] == 1){
            dup--;
        }

        // cout << v[1] << endl;
        dq.push_front(v[1]);

        if(dup == 0){
            cout << dq.size() << endl;
            break;
        }
    }

    return 0;
}
