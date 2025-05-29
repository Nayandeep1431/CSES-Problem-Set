#include<bits/stdc++.h>
using namespace std ;
int mod = 1e9 + 7 ;
typedef long long ll ;

int main(){
	ll k ;
	cin>> k ;
	for(ll i = 1; i<= k ; i++){
		ll totalCombination = ((i*i)* ((i*i) - 1)) / 2 ;
		ll attacks = 4* (i-1)*(i-2) ;
		cout<< totalCombination - attacks <<endl ;
	}
	return 0 ;
}
