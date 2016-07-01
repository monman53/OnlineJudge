#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> origin;
    vector<int> data;
    for(int i=0;i<n;i++){
        int p;
        cin >> p;
        origin.push_back(p);
        data.push_back(p);
    }
    sort(data.begin(), data.end());
    // check origin sorted
    for(int i=0;i<n;i++){
        if(origin[i] != data[i]){
            break;
        }
        if(i == n-1){
            printf("0.000000\n");
            return 0;
        }
    }
    
    vector<int> same;
    int count = 1;
    int before = data[0];
    for(int i=1;i<n;i++){
        if(before == data[i]){
            count++;
        }
        if(i == n-1 || before != data[i]){
            if(count > 1){
                same.push_back(count);
            }
            count = 1;
        }
        before = data[i]; 
    }

    double e = 0;
    double p = 1;

    for(int i=1;i<=n;i++){
        p *= i;
        if(i-1 < (int)same.size()){
            for(int j=1;j<=same[i-1];j++){
                p /= j;
            }
        }
    }

    for(int i=0;i<(int)same.size();i++){
        for(int j=1;j<=same[i];j++){
        }
    }
    //
    // if(equals(p, 1)){
    //     printf("0.000000\n");
    //     return 0;
    // }
    //
    double bunbo = p;
    for(int i=1;;i++, bunbo*=p){
        // printf("%7f\n", e);
        
        e += i/bunbo;
        if(equals(i/bunbo, 0)){
            break;
        }
    }

    printf("%7lf\n", e);

    return 0;
}
