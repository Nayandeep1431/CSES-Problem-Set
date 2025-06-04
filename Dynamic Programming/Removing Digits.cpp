#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7 ;


// Recursion
int solve(int n){
    if(n == 0)
        return 0 ;
    
    if(n < 0)
        return INT_MAX ;
    
    int mini = INT_MAX ;
    int num = n ;
    while(num > 0){
        int val = num % 10 ;
        num = num / 10 ;
        
        if(val == 0)
            continue ;
        int ans = solve(n - val) ;
        if(ans != INT_MAX)
            mini = min(mini , 1 + ans) ;
    }
    return mini ;
}

// Memoization
int solveMem(int n , vector<int> dp){
    if(n == 0)
        return 0 ;
    
    if(n < 0)
        return INT_MAX ;
    if(dp[n] != -1)
        return dp[n] ;
        
    int mini = INT_MAX ;
    int num = n ;
    while(num > 0){
        int val = num % 10 ;
        num = num / 10 ;
        
        if(val == 0)
            continue ;
        int ans = solveMem(n - val, dp) ;
        if(ans != INT_MAX)
            mini = min(mini , 1 + ans) ;
    }
    return dp[n] = mini ;
}


// Tabulation
int solveTab(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int num = i;

        while (num > 0) {
            int digit = num % 10;
            num /= 10;

            if (digit == 0) continue;
            if (i - digit >= 0 && dp[i - digit] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - digit]);
        }
    }

    return dp[n];
}


int main() {
    ll n  ;
    cin>> n  ;
    
    // cout<<solve(n)<<endl ;
    
    // Memoization
//     vector<int> dp(n+1 , -1) ;
//   cout<< solveMem(n , dp) ;
   
   cout<< solveTab(n) ;
    return 0;
}
