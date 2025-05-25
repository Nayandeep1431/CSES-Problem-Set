#include<bits/stdc++.h>
using namespace std ;
int mod = 1e9 + 7 ;
long long solve(vector<int> &arr ,int n){
   int prev = arr[0] ;
   if(n == 1)
    return 0 ;
   long long cnt = 0 ;
   for(int i = 1 ; i< n ; i++){
       int ele = arr[i] ;
       if(ele > prev){
           prev = ele ;
           continue ;
       }
       else{
           cnt = (cnt +  (prev - ele ) ) ;
       }
   }
   return cnt ;
}

int main(){
    int n ;
    cin>> n ;
    vector<int> arr ;
    for(int i =0 ; i< n ; i++){
        int val ;
        cin>> val ;
        arr.push_back(val) ;
    }
    
    cout<< solve(arr , n) ;
}
