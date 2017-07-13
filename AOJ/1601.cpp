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
// #include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    (26)
#define EPS         (1e-10)
#define INF         (1000000005LL)
#define MOD         (1000000007LL)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
// ciling(x/y) = (x+y-1)/y

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    while(true){
        int n;cin >> n;
        if(n == 0) break;
        vector<int> w(n);
        for(int i=0;i<n;i++){
            string s;cin >> s;
            w[i] = s.size();
        }

        vector<int> v5(n, 0);
        vector<int> v7(n, 0);
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=i;j<n;j++){
                count += w[j];
                if(count == 5){
                    v5[i] = j+1;
                }
                if(count == 7){
                    v7[i] = j+1;
                }
                if(count > 7){
                    break;
                }
            }
        }

        for(int i=0;i<n;i++){
            int next;
            if(next = v5[i]){
                if(next = v7[next]){
                    if(next = v5[next]){
                        if(next = v7[next]){
                            if(next = v7[next]){
                                cout << i+1 << endl;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
