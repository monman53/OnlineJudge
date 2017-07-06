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

bool solve(string s){
    // cout << s << endl;
    if(s.size() < 3){
        return false;
    }
    if(s == "ABC"){
        return true;
    }
    for(auto c : "ABC"){
        string ns = "";
        int count = 0;
        for(int i=0;i<int(s.size());){
            if(i<int(s.size())-2){
                if(s.compare(i, 3, "ABC") == 0){
                    ns += c;
                    i += 3;
                    count++;
                }else{
                    if(s[i] == c){
                        count = 0;
                        break;
                    }
                    ns += s[i];
                    i++;
                }
            }else{
                if(s[i] == c){
                    count = 0;
                    break;
                }
                ns += s[i];
                i++;
            }
        }
        if(count > 0){
            if(solve(ns)){
                // cout << ns << endl;
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;cin >> s;
    cout << (solve(s) ? "Yes" : "No") << endl;
    return 0;
}
