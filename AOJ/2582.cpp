#include <iostream>
#include <string>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        int count = 0;
        bool left=false,right=false;
        bool next=true;
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            if(s[0] == 'l') left = !left;
            else right = !right;
            if(right == next && left == next){
                count++;
                next = !next;
            }
        }
        cout << count << '\n';
    }
    return 0;
}
