#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int main(){
	long long n ; 
	cin>> n ;
	ll num = n ;
	ll ans = 0 ;
	ll i = 5;
	while(i <= n){
		ll val = n / i ;
		ans += val ;
		i = i*5 ;
	}
		cout<<ans ;
}
