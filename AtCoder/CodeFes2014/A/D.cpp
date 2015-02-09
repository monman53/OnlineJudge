#include <iostream>
#include <string>
using namespace std;

string s;
int sn[17];
int n;
bool use[10];
long long int min = 99999999999999999;


int main(){
    cin >> s >> n;
    int slength = s.size();
    for(int i=0;i<s.size;i++){
        sn[i] = s[i] - '0';
    }
    for(int i=0;i<10;i++){
        use[i] = false;
    }

    int start=0;
    int count=0;
    for(start=0;;start++){
        if(!use[sn[start]]){
            use[sn[start]] = true;
            count++;
            if(count == n-1){
                break;
            }
        }
    }

    

    if(start >= n-2){
        
    
    return 0;
}
