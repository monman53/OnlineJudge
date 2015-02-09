#include <iostream>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;
        if(n==0){
            break;
        }
        int min = 99999999;
        int max = -1;
        int sum = 0;
        for(int i=0;i<n;i++){
            int point;
            cin >> point;
            if(point > max){
                max = point;
            }
            if(point < min){
                min = point;
            }
            sum += point;
        }
        cout << (sum-max-min)/(n-2) << "\n";
    }
    return 0;
} 
