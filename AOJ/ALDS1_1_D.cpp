#include <iostream>
using namespace std;

int main(){
    int data[200000];
    long int max=-99999999999;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> data[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(data[j] - data[i] >= max){
                max = data[j] - data[i];
            }
        }
    }
    cout << max <<'\n';
    return 0;
}
