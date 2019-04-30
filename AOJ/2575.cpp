#include <iostream>
using namespace std;

int main(){
    int count[26];
    for(int i=0;i<26;i++){
        count[i] = 0;
    }
    string s;
    cin >> s;
    int j=0;
    for(int i=0;i<s.size();i++,j++){
        count[int(s[i] - 'A')]++;
        if(j>=8){
            //if(count[int(s[i-8] - 'A')] != 0){
                count[int(s[i-8] - 'A')]--;
                //}
        }
        if(count['A' - 'A'] == 2 && count['I' - 'A'] == 1 && count['D' - 'A'] == 1 && count['U' - 'A'] == 1 && count['N' - 'A'] == 2 && count['Y' - 'A']){
            s[i-7] = 'A';
            s[i-6] = 'I';
            s[i-5] = 'Z';
            s[i-4] = 'U';
            s[i-3] = 'N';
            s[i-2] = 'Y';
            s[i-1] = 'A';
            s[i-0] = 'N';
            count['A' - 'A'] = 0;
            count['I' - 'A'] = 0;
            count['D' - 'A'] = 0;
            count['U' - 'A'] = 0;
            count['N' - 'A'] = 0;
            count['Y' - 'A'] = 0;
            j=-1;
        }
    }
    cout << s << '\n';
    return 0;
}
