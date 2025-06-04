#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7 ;


// Recursion
int solve(vector<int> &books , vector<int> &pages , int capacity , int ind){
    if(ind == 0){
        if(books[0] <= capacity)
            return pages[0] ;
        else
            return 0 ;
    }
    
    int notTake = solve(books , pages , capacity , ind-1) ;
    int take =0 ;
    if(books[ind] <= capacity)
        take = pages[ind] + solve(books ,pages , capacity - books[ind] , ind-1) ;
    
    return max(take , notTake) ;    
}

// Memoization
int solveMem(vector<int> &books , vector<int> &pages , int capacity , int ind , vector<vector<int>> &dp){
    if(ind == 0){
        if(books[0] <= capacity)
            return pages[0] ;
        else
            return 0 ;
    }
    
    if(dp[ind][capacity] != -1)
        return dp[ind][capacity] ;
        
    int notTake = solveMem(books , pages , capacity , ind-1 ,dp) ;
    int take =0 ;
    if(books[ind] <= capacity)
        take = pages[ind] + solveMem(books ,pages , capacity - books[ind] , ind-1 , dp) ;
    
    return dp[ind][capacity] = max(take , notTake) ;    
}

// Tabulation
int solveTab(vector<int>&books , vector<int> &pages , int capacity){
    int n = books.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    for (int i = 0; i <= capacity; i++) {
        if (books[0] <= i)
            dp[0][i] = pages[0]; 
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= capacity; j++) {
            int notTake = dp[i - 1][j];
            int take = 0;
            if (books[i] <= j)
                take = pages[i] + dp[i - 1][j - books[i]]; 

            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][capacity];
}


int main() {
    int n , x ;
    cin>> n >> x ;
    
    vector<int> books(n) , pages(n) ;
    for(int i =0 ; i< n ; i++)
        cin >> books[i] ;
    
    for(int j =0 ; j< n ; j++)
        cin >> pages[j] ;
        
    
    //  cout<< solve(books, pages , x , n-1) ;
    
    //  vector<vector<int>> dp(n , vector<int> (x+1 , -1)) ;
    // cout<< solveMem(books, pages , x , n-1 , dp) <<endl ;
     
    cout<< solveTab(books , pages, x)<<endl ;
    return 0;
}
