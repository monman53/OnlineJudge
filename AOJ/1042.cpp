#include <iostream>
using namespace std;

int main(){
    string s;
    while(1){
        getline(cin, s);

        if(s == "END OF INPUT"){
            break;
        }
        
        int counter = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                cout << counter;
                counter = 0;
            }else{
                counter++;
            }
        }
        cout << counter;
        cout << '\n';
    }
}
