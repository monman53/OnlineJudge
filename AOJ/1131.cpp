#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll gcd(ll x, ll y){
  return y ? gcd(y, x%y) : x;
}

int ans(int p, int q, int a, int n, int start, int product, vector<int> v){
    int ret = 0;
    int sum = 0;
    for(int i=0;i<v.size();i++){
        sum += product / v[i];
    }
    int g = gcd(product, sum);
    if(sum/g == p && product/g == q){
        return 1;
    }
    if(n!=0){
        for(int i=start;i*product<=a;i++){
            v.push_back(i);
            ret += ans(p, q, a, n-1, i, i*product, v);
        }
    }
    return ret;
}

int main(){
    vector<int> v;
    cout << ans(2, 3, 120, 3, 1, 1, v) << endl;
    return 0;
}
