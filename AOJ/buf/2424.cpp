#include <iostream>
#include <set>
#include <string>
using namespace std;

string reverse(string s){
    string ret="";
    for(int i=s.size()-1;i>=0;i--){
        ret += s[i];
    }
    return ret;
}

string ntos(int n){
    string ret="";
    if(n == 0) return "0";
    for(int i=1;;i*=10){
        if(n/i > 0){
            ret += char('0' + (n/i)%10);
        }else{
            break;
        }
    }
    return reverse(ret);
}

int ston(string s){
    int ret=0;
    int i,j;
    for(i=s.size()-1,j=1;i>=0;i--,j*=10){
        ret += int(s[i] - '0')*j;
    }
    return ret;
}

int main(){
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int n;
        int found[1000000];
        cin >> found[0];
        for(int j=0;;j++){
            //cout << j << ": " << found[j] << '\n';
            if(found[j]/10 == 0){
                cout << j << '\n';
                break;
            }
            bool inf=false;
            for(int k=0;k<j;k++){
                if(found[k] == found[j]){
                    cout << (j-k) << '\n';
                    inf = true;
                    break;
                }
            }
            if(inf) break;

            string ns = ntos(found[j]);
            //cout << "ns=" << ns << '\n';
            int max=0;
            for(int i=0;i<ns.size()-1;i++){
                //cout << ns.substr(0,i+1) << ' ' << ns.substr(i+1) << '\n';
                int buf=ston(ns.substr(0,i+1))*ston(ns.substr(i+1)); 
                if(buf >= max){
                    max = buf;
                }
            }
            found[j+1] = max;
        }
    }
    return 0;
}
