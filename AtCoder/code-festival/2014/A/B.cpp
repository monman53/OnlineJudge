#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    int n;
    cin >> s;
    cin >> n;
    n = n%(s.size());
    if(n == 0){
        cout << s[s.size()-1] <<"\n";
    }else{
        cout << s[n-1] <<"\n";
    }
    return 0;
}

