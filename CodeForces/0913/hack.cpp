#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;
    long long j = pow(2, n);
    cout << m%j;
}
