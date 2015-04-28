#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t,n;
    long long int a[1002];
    long long int ab[1002];
    long long int sum;
    int kumi[1001];
    kumi[3] = 1;
    for(int i=4;i<1001;i++){
        kumi[i] = kumi[i-1] + (i - 2);
        cout << "@"<< kumi[i] <<'\n';
    }
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        for(int j=0;j<n;j++){
            cin >> a[j];
        }
        sort(a,a+n);
        for(int j=0;j<n;j++){
            ab[j] = a[n-1-j];
        }
        for(int j=0;j<n;j++){
            a[j] = ab[j];
            cout <<"data: " << a[j] << '\n';
        }
        sum = 0;
        while(a[2]>0){
            for(int j=0;j<1002;j++){
                ab[j] = a[j];
            }
            for(int j=n-1;j>=2;j--){
                if(a[j]>=kumi[j+1]){
                    cout << "::" << j+1 << " : " << kumi[j+1] << '\n';
                    for(int k=0;k<=j;k++){
                        ab[k] = a[k] - (a[j]/kumi[j+1])*kumi[j+1];
                    }
                    sum += (j+1)*kumi[j+1]*(a[j]/kumi[j+1])/3;
                    break;
                }
            }
            sort(ab,ab+n);
            for(int j=0;j<n;j++){
                a[j] = ab[n-1-j];
                cout << "|" << a[j]; 
            }
            for(int j=0;j<=n;j++){
                if(a[j]==0){
                    n=j;
                    break;
                }
            }
            cout << sum << "\n";
        }
        cout << sum << '\n';
    }
    return 0;
}
