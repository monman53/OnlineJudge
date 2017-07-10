#include <iostream>
using namespace std;

int main(){
    int count[26];
    for(int i=0;i<26;i++){
        count[i] = 0;
    }

    string s;
    cin >> s;

    for(int j=0;j<s.size();j++){
        count[s[j] - 'a']++;
    }

    string ans = "yes";
    for(int i=0;i<26;i++){
        if(count[i] > 1){
            ans = "no";
            break;
        }
    }

    cout << ans << endl;
    
    return 0;
}
