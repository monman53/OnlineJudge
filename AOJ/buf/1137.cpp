#include <iostream>
#include <map>
using namespace std;

map<char, int> mcxi;
char data[] = {'m','c','x','i'};

int ston(string s){
    int ret=0;
    int buf=1;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'm' || s[i] == 'c' || s[i] == 'x'|| s[i] == 'i'){
            ret += buf*mcxi[s[i]];
            buf = 1;
        }else{
            buf = s[i] - '0';
        }
    }
    return ret;
}

string ntos(int n){
    string ret="";
    int i,j;
    for(i=0,j=1000;i<4;i++,j/=10){
        if((n/j)%10 == 1) ret += data[i];
        if((n/j)%10 >  1){
            ret += char('0' + (n/j)%10);
            ret += data[i];
        }
    }
    return ret;
}

int main(){
    int n;
    mcxi['m'] = 1000;
    mcxi['c'] = 100;
    mcxi['x'] = 10;
    mcxi['i'] = 1;
    cin >> n;
    for(int i=0;i<n;i++){
        string sl,sr;
        cin >> sl >> sr;
        cout << ntos(ston(sl) + ston(sr)) << '\n';
    }
    return 0;
}
