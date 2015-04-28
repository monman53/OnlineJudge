#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int count=0;
    int size = s.size();
    int j;
    for(int i=0;i<size/2;i++){
        j = size - i - 1;
        if(s[i] == s[j]){
            if(s[i] == '(' || s[i] == ')'){
                count++;
            }
        }else{
            if(!((s[i] == '(' && s[j] == ')') || (s[i] == ')' && s[j] == '('))){
                count++;
            }
        }
        if(size%2 == 1 && i == size/2 - 1){
            if(s[i+1] == '(' || s[i+1] == ')'){
                count++;
            }
        }
    }

    cout << count << '\n';
        
    return 0;
}
