#include <iostream>
using namespace std;

int main(){
    int atta[10000];
    for(int i=0;i<10000;i++){
        atta[i] = false;
    }
    int n;
    int data[1000];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> data[i];
        atta[data[i]] = true;
        if(i >= 1){
            atta[data[i-1]*10 + data[i]] = true;
        }
        if(i >= 2){
            atta[data[i-2]*100 + data[i-1]*10 + data[i]] = true;
        }
        if(i >= 3){
            atta[data[i-3]*1000 + data[i-2]*100 + data[i-1]*10 + data[i]] = true;
        }
    }

    for(int i=0;;i++){
        if(!atta[i]){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
