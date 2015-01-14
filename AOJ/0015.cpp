#include <iostream>
using namespace std;

int main(){
    int n;
    string s;
    int data[80];

    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<80;j++) data[j] = 0;
        bool overflow=false;
        cin >> s;
        if(s.size() > 80) overflow = true;
        if(!overflow) for(int j=0;j<s.size();j++) data[s.size() - j - 1] = int(s[j] - '0');
        cin >> s;
        if(s.size() > 80) overflow = true;
        if(!overflow) for(int j=0;j<s.size();j++) data[s.size() - j - 1] += int(s[j] - '0');
        
        if(!overflow){
            while(1){
                bool change=false;
                for(int j=0;j<80;j++){
                    if(data[j] >= 10){
                        if(j == 79){
                            overflow = true;
                            break;
                        }else{
                            data[j+1] += data[j]/10;
                            data[j] = data[j]%10;
                        }
                        change = true;
                    }
                }
                if(!change || overflow) break;
            }
        }

        if(overflow){
            cout << "overflow\n";
        }else{
            for(int j=79;j>=0;j--){
                if(data[j] > 0 || j == 0){
                    for(int k=j;k>=0;k--) cout << data[k];
                    cout << '\n';
                    break;
                }
            }
        }

    }
    return 0;
}
