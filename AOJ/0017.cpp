#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    char c;
    string s;
    while(getline(cin,s)){
        while(1){
            for(int i=0;i<s.size();i++){
                if(s[i] != '.' && s[i] != ' ' && s[i] != '\n'){
                    s[i] = char(int('a') + (int(s[i] - 'a') + 1)%26);
                } 
            }
            if(s.find("the",0) != string::npos || s.find("this",0) != string::npos || s.find("that",0) != string::npos){
                cout << s << '\n';
                break;
            }
        }
    }
    return 0;
}
