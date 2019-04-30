#include <iostream>
using namespace std;

int main(){
    int t,n;
    int count;
    int s[1000];
    char c;
    cin >> t;
    for(int i=0;i<t;i++){
        count = 0;
        cin >>n;
        for(int j=0;j<n;j++){
            cin >> c;
            if(c=='+'){
                s[count-2] = s[count-2] + s[count-1];
                count--;
            }else if(c=='-'){
                s[count-2] = s[count-2] - s[count-1];
                count--;
            }else if(c=='*'){
                s[count-2] = s[count-2] * s[count-1];
                count--;
            }else if(c=='/'){
                s[count-2] = s[count-2] / s[count-1];
                count--;
            }else{
                s[count] = c - '0';
                count++;
            }
        }
        cout << s[0] << '\n';
    }
    return 0;
}
