#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	long long int a[10005], b[10005], c[10005];
	long long int dpa[100005], dpb[100005], dpc[100005];
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	dpa[0] = a[0];
	dpb[0] = b[0];
	dpc[0] = c[0];
	for(int i=0;i<n;i++){
		dpa[i+1] = a[i+1]+max(dpb[i],dpc[i]);
		dpb[i+1] = b[i+1]+max(dpa[i],dpc[i]);
		dpc[i+1] = c[i+1]+max(dpa[i],dpb[i]);
	}
	cout << max(dpa[n-1],(max(dpb[n-1],dpc[n-1]))) << endl;
	return 0;
}