#include<bits/stdc++.h>
using namespace std ;
const int mod = 1e9+7 ;
vector<vector<int>> dp(1e6+1 , vector<int>(2)) ;

int main(){
	int k ;
	cin>> k ;
	while(k--){
		int n ;
		cin >> n ;
		
		// dp[i][0] number of ways to fill the grid from ith row to the top such that there 
		// is a 1*2 block on th i- 1 th row trying to extend forward
		
		// dp[i][1] number of ways to fill the grid from ith row to the top such that there 
		// is are 2 1*1 block on th i- 1 th row trying to extend forward
		
		dp[n][0] = 1 ;
		dp[n][1] = 1 ;
		
		for(int i = n-1 ; i>=0 ; i--){
			dp[i][0] = (2LL * dp[i+1][0] + dp[i+1][1]) % mod ;
			dp[i][1] = (4LL * dp[i+1][1] + dp[i+1][0]) % mod ;
		}
		cout<< (dp[1][0] + dp[1][1]) % mod << endl ; 
	}
}
