#include <iostream>
#include <algorithm>
using namespace std;

int l;

string ntos(int n){
    string ret="";
    int i,j;
    for(i=0,j=1;i<l;i++,j*=10) ret += char('0' + (n/j)%10);
    return ret;
}

int ston(string s){
    int ret=0;
    int i,j;
    for(i=0,j=1;i<l;i++,j*=10) ret += int(s[i] - '0')*j;
    return ret;
}

string reverse(string s){
    string ret=s;
    for(int i=0;i<l;i++) ret[i] = s[l-i-1];
    return ret;
}

int main(){
    while(1){
        int a[1000000];
        cin >> a[0] >> l;
        if(l==0) break;
        bool found=false;
        for(int i=1;!found;i++){
            string ba = ntos(a[i-1]);
            sort(&ba[0], &ba[0] + ba.size());
            string la,ra;
            ra = reverse(ba);
            la = ba;
            a[i] = ston(ntos(ston(la) - ston(ra)));
            for(int j=0;j<i;j++){
                if(a[j] == a[i]){
                    cout << j << ' ' << a[i] << ' ' << (i-j) << '\n';
                    found = true;
                    break;
                }
            }
        }
    }
    return 0;
}
