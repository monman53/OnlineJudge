#include <iostream>
#include <string>
using namespace std;

int main(){
    int data[26] = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0};
    while(1){
        string s;
        cin >> s;
        if(s[0] == '#'){
            break;
        }
        int count = 0;
        for(int i=1;i<s.size();i++){
            if(data[int(s[i-1] - 'a')] != data[int(s[i] - 'a')]){
                count++;
            }
        }
        cout << count << '\n';
    }
    return 0;
}
