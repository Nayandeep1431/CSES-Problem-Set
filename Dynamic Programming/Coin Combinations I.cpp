#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

// Recursion
ll solve(vector<int> & nums , int x){
    if( x == 0)
        return 1 ;
    if(x < 0 ) 
        return 0 ;
    
    long long ans = 0 ;
    for(int i =0 ; i< nums.size() ; i++){
         ans += solve(nums , x - nums[i]) ;
    }
    return ans ;
}

// Memoization
int solveMem(const vector<int> &nums, int x, vector<ll> &dp) {
    if (x == 0)
        return 1;
    if (x < 0)
        return 0;

    if (dp[x] != -1)
        return dp[x];

    int ans =0 ;
    for (int i = 0; i < nums.size(); i++) {
        ans += solveMem(nums, x - nums[i], dp);
    }

    return dp[x] = ans % mod;
}


// Tabulation
int solveTab(const vector<int>& arr, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int tar = 1; tar <= target; tar++) {
        for (int i = 0; i < arr.size(); i++) {
            if (tar - arr[i] >= 0) {
                dp[tar] = (dp[tar] + dp[tar - arr[i]]) % mod;
            }
        }
    }
    return dp[target];
}


int main() {
    ll n ,x ;
    cin>> n >>x ;
    
    vector<int> arr(n) ;
    for(int i =0 ; i< n ; i++)
        cin>> arr[i] ;
    // cout<< solve(arr , x) ;   

    // vector<int> dp(x + 1, -1);
    // ll result = solveMem(arr, x, dp);
    // // cout << (result == LLONG_MAX ? -1 : result) << endl;
    cout<< solveTab(arr , x) ;
    
    return 0;
}
