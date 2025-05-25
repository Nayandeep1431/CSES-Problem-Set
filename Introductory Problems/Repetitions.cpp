#include<bits/stdc++.h>
using namespace std ;
int solve(string s){
    int n = s.length() ;
    char c = s[0] ;
    int maxi = 1 ;
    int cnt = 1;
    for(int i =1 ; i< n ; i++ ){
        char ch = s[i] ;
        if(ch == c){
            cnt++ ;
        }
        else{
            cnt = 1 ;
            c = ch ; 
        }    
        
        maxi = max(maxi , cnt) ;    
    }
    return maxi ;
}

int main(){
    string n ;
    cin>> n ;
    
    cout<< solve(n) ;
}
