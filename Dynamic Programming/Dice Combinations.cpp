#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1e9 + 7 ;
vector<ll> dp ;

// Recursion
ll solve(int n){
    if(n == 0)
        return 1 ;
    ll ans =0 ;
    for(int i =1 ; i<= 6 ; i++){
       if(n - i >=0)
        ans += solve(n- i) ;
    }    
    return ans ;
}

// Memoization
ll solveMem(int n ,vector<ll> &dp){
    if(n == 0)
        return 1 ;
        
    if(dp[n] != -1)
        return dp[n] ;
        
    ll ans =0 ;
    for(int i =1 ; i<= 6 ; i++){
       if(n - i >=0)
        ans += solveMem(n- i , dp) ;
    }    
    return dp[n] = (ans) % mod ;
}

// Tabulation
ll solveTab(int n){
    vector<int> dp(n+1 , 0) ;
    dp[0] = 1;
    for(int i = 1 ; i<= n ; i++){
        ll ans = 0 ;
        for(int j = 1 ; j <= 6 ; j++){
            if(i - j >= 0)
                ans += dp[i-j] ;
        }
        dp[i] = ans % mod ;
    }
    return dp[n] ;
}

int main() {
    ll n ;
    cin>> n ;
    vector<ll> dp(n+1 , -1) ;
    // cout<< solve(n)<<endl ;
    // cout<< solveMem(n , dp) <<endl ;
    cout<< solveTab(n) ;
    
    return 0;
}
