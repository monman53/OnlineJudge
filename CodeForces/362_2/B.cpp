// includes, macros {{{
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <functional>
#include <numeric>
#include <limits>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
 
typedef long long ll;
typedef unsigned long long ull; // }}}

int main(){
    string s;
    cin >> s;
    string d="";
    int length = 0;
    string b = "";
    char a = s[0];
    for(int i=2;i<s.size();i++){
        if(s[i] == 'e'){
            for(int j=i+1;j<s.size();j++){
                b += s[j];
            }
            break;
        }else{
            d += s[i];
        }
    }
    stringstream ss;
    ss << b;
    int bb;
    ss >> bb;

    stringstream sd;
    sd << d;
    int dd;
    sd >> dd;

    if(dd == 0 && bb == 0){
        cout << a <<endl;
        return 0;
    }

    if(a == '0'){
        cout << 0 << ".";
        for(int i=0;i<d.size();i++){
            cout << d[i];
        }
        cout << endl;
        return 0;
    }


    string ans = "";
    ans += a;
    for(int i=0;i<d.size();i++){
        if(bb == 0){
            ans += '.';
        }
        ans += d[i];
        bb--;
    }
    for(int i=0;i<bb;i++){
        ans += '0';
    }
    cout << ans << endl;
    // bool flag = true;
    // for(int i=0;i<ans.size();i++){
    //     if(ans[i] == '0' && ans[i+1] != '.' && flag){
    //     }else{
    //         cout << ans[i];    
    //         flag = false;
    //     }
    // }
    // cout << endl;
    return 0;
}
