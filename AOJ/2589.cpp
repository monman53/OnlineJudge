#include <iostream>
using namespace std;

void madd(int *s,int *b,int nine,int n){
    *s = *s*(1 << n) + nine**b;
    *b = *b*(1 << n);
    while(*s%2 == 0 && *b%2 == 0){
        *s /= 2;
        *b /= 2;
    }
}

int main(){
    string str;
    int s,b;
    while(1){
        cin >> str;
        if(str == "#") break;
        char bc=str[0];
        s=0;
        b=1;
        s = (str[0] == 'n') ? 0 : 90;
        int i = (str[0] == 'n') ? 5 : 4;
        for(int count=1;i < str.size();count++){
            if(str[i] != bc){
                madd(&s,&b,((str[i]=='n') ? -90 : 90),count);
            }
            bc = str[i];
            i += (str[i] == 'n') ? 5 : 4;
        }
        cout << s;
        if(b!=1){
            cout << '/' << b;
        }
        cout <<'\n';
    }
    return 0;
}
