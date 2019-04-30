#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int x, long long int y){
    cout << x << y << endl;
	long long int z = y-x;
	if(z==0){
		return x;
	}
	else if(x%z==0){
		return z;
	}else{
		return gcd(x, z);
	}
	return 1;
}

int main() {
    cout << gcd(6, 15) << endl;
    return 0;
}
