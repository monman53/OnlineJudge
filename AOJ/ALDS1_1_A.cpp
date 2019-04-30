#include <iostream>
using namespace std;

int main(){
    int n;
    int A[100];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
        cout << A[i];
        if(i!=n-1){
            cout << ' ';
        }
    }
    cout << '\n';
    for(int i=1;i<n;i++){
        int buf;
        buf = A[i];
        for(int j=0;j<=i;j++){
            if(buf < A[j] || j==i){
                for(int k=i;k>j;k--){
                    A[k] = A[k-1];
                }
                A[j] = buf;
                break;
            }
        }
        for(int j=0;j<n;j++){
            cout << A[j];
            if(j!=n-1){
                cout << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
