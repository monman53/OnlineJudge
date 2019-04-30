    #include <cstdio>
    #include <cstring>
    #include <algorithm>
     
    using namespace std;
    typedef long long ll;
     
    ll k, step = 10;
     
    inline double getval( ll x ){
    	ll y = 0;
    	for( ll i = x; i; i /= 10 ) y += i % 10;
    	return (double)x / (double)y;
    }
     
    int main(){
    	scanf( "%lld", &k );
    	for( int i = 1; i <= 9 && k; ++i, --k )
    		printf( "%d\n", i );
    	for( ll i = 19; k; i += step, --k ){
    		while( getval(i+step) > getval(i+step+step) )
    			step *= 10;
    		printf( "%lld\n", i );
    	}
    	return 0;
    }
