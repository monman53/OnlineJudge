#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<char, char> m;
string s;
int mleft,mright;
char ldata[15];
char rdata[15];
bool ruse[15];

int mmax;

void dfs(int n,int count){
    if(n == mleft){
        if(count > mmax){
            mmax = count;
        }
        return;
    }
    bool flag=true;
    int start;
    for(int i=0;i<mright;i++){
        if(flag && ruse[i]){
            start = i;
            flag = false;
        }
        if(rdata[i] == m[ldata[n]] && ruse[i]){
            dfs(n+1,count);
            for(int j=start;j<=i;j++){
                ruse[j] = false;
            }
            dfs(n+1,count+1);
            for(int j=start;j<=i;j++){
                ruse[j] = true;
            }
            break;
        }
        if(i == mright-1){
            dfs(n+1,count);
        }
    }
}

int main(){
    m['('] = ')';
    m[')'] = '(';
    m['{'] = '}';
    m['}'] = '{';
    m['['] = ']';
    m[']'] = '[';

    cin >> s;
    mmax = 0;
    for(int i=0;i<15;i++){
        ruse[i] = true;
    }
    for(int i=0;i<s.size();i++){
        if(s[i] == 'i'){
            mleft = i;
            for(int j=0;i+3+j<s.size();j++){
                rdata[j] = s[s.size() - j - 1];
            }
            mright = s.size() - mleft;
            break;   
        }else{
            ldata[i] = s[i];
        }
    }
    dfs(0,0);
    cout << (mmax*2+3) << '\n';
    return 0;
}
