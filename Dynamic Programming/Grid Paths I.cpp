#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7 ;


// Recursion
int solve(int i, int j , vector<vector<char>> &grid ,int n){
    if(i == n-1 && j == n-1)
        return 1 ;
    
    if(i >= n || j >= n)
        return 0 ;
    
    if(grid[i][j] == '*')
        return 0 ;
        
    int right = solve(i , j+1 , grid , n) ;
    int down = solve(i+1 , j , grid , n) ;
    
    return (right + down) % mod ;
}

// Memoization
int solveMem(int i, int j , vector<vector<char>> &grid ,int n , vector<vector<int>> &dp){
    if(i == n-1 && j == n-1)
        return 1 ;
    
    if(i >= n || j >= n)
        return 0 ;
    
    if(grid[i][j] == '*')
        return 0 ;
    
    if(dp[i][j] != -1)
        return dp[i][j] ;
        
    int right = solveMem(i , j+1 , grid , n , dp) ;
    int down = solveMem(i+1 , j , grid , n , dp) ;
    
    return dp[i][j] = (right + down) % mod ;
}

// Tabulation
int solveTab(vector<vector<char>> &grid , int n){
    vector<vector<int>> dp(n+1 , vector<int> (n+1 , 0)) ;
    
    for(int i = n-1 ; i>=0 ; i-- ){
        for(int j = n-1 ; j>= 0 ; j--){
            if(i == n-1 && j == n-1){
                dp[i][j] = 1 ;
                continue ;
            }
            
            if(grid[i][j] == '*'){
                dp[i][j] = 0 ;
                continue ;
            }
            
            int right = dp[i][j+1] ;
            int down = dp[i+1][j] ;
            
            dp[i][j] = (right + down) % mod ;
        }
    }
    return dp[0][0] ;
}

int main() {
    int n  ;
    cin>> n  ;
    
    vector<vector<char>> grid(n , vector<char> (n)) ;
    for(int i =0 ; i< n ; i++){
        for(int j =0 ; j< n ; j++){
            cin >> grid[i][j] ;
        }
    }
    
    if(grid[0][0] == '*' || grid[n-1][n-1] == '*'){
        cout<< "0"<<endl ;
        return 0 ;
    }
        
    
    // cout<< solve(0 ,0 , grid , n) ;
    
    //  vector<vector<int>> dp(n , vector<int> (n , -1)) ;
    //  cout<< solveMem(0 , 0 , grid , n , dp) <<endl ;
     
    cout<< solveTab(grid , n)<<endl ;
    return 0;
}
