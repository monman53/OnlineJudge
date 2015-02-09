#include <iostream>
using namespace std;

long long int pr(int n){
    long long int ret=1;
    for(int i=1;i<=n;i++){
        ret *= i;
    }
    return ret;
}

int main(){
    string s;
    int data[26];
    long long int ans=1;
    for(int i=0;i<26;i++) data[i] = 0;
    cin >> s;
    for(int i=0;i<s.size();i++){
        data[int(s[i] - 'a')]++;
    }
    for(int i=1;i<=s.size()/2;i++){
        ans *= i;
    }
    int count = 0;
    int kcount = 0;
    for(int i=0;i<26;i++){
        if(data[i]%2 == 1){
            kcount++;
        }
        ans /= pr(data[i]/2);
    }
    if(kcount <= 1){
        cout << ans <<'\n';
    }else{
        cout << 0 << '\n';
    }
    return 0;
}
