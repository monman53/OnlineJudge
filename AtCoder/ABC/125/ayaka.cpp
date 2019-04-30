    #include <bits/stdc++.h>
    using namespace std;
     
    long long int gcd(long long int x, long long int y){
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
    	int n; cin >> n;
    	long long int a[100005];
    	for(int i=0;i<n;i++){
    		cin >> a[i];
    	}
    	if(n==2){
    		cout << max(a[0], a[1]) << endl;
    		return 0;
    	}
    	sort(a, a+n);
    	long long int ans = 0LL;
    	for(int i=0;i<n-2;i++){
    		long long int v = max(gcd(a[i], a[i+1]), gcd(a[i], a[i+2]));
    		ans = gcd(ans, v);
    	}
    	ans = max(ans, max(gcd(a[n-1], a[0]), gcd(a[n-1], a[n-2])));
    	cout << ans << endl;
    	return 0;
    }
