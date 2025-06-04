#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7 ;

// Longest common subsequence
void lcs(vector<int>& s1 ,vector<int> &s2 ){
    int n = s1.size() ;
    int m = s2.size() ;
    
    vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0)) ;
    for(int i =1 ; i<= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1] ;
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;
            }    
        }
    }
    cout<<dp[n][m]<<endl ;
    int len = dp[n][m] ;
    
    int i = n ;
    int j = m ;
    
    vector<int> ans(len) ;
    int ind = len - 1 ;
    
    while(i > 0 && j >0){
        if(s1[i-1] == s2[j-1]){
            ans[ind] = s1[i-1] ;
            i-- ;
            j-- ;
            ind-- ;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i-- ;
        else
            j-- ;
    }
    for(auto it : ans){
        cout<< it <<" " ;
    }
}

int main() {
    int n , x ;
    cin>> n >> x ;
    
    vector<int> books(n) , pages(x) ;
    for(int i =0 ; i< n ; i++)
        cin >> books[i] ;
    
    for(int j =0 ; j< x ; j++)
        cin >> pages[j] ;
        
    lcs(books , pages) ;
     
    return 0;
}
