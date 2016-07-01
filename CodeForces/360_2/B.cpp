#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    string s;
    cin >> s;
    cout << s;
    for(int i=s.size()-1;i>=0;i--){
        printf("%c", s[i]);
    }
    printf("\n");
}
