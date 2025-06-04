#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7 ;

// Longest Increasing subsequence
int lis(vector<int> &arr){
    vector<int> temp ;
    temp.push_back(arr[0]) ;
    int n = arr.size() ;
    
    for(int i =1 ; i< n ; i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]) ;
        }
        else{
           	int index = lower_bound(temp.begin() , temp.end() , arr[i]) - temp.begin();
			temp[index] = arr[i] ;
			}
    }
    return temp.size() ;
}

int main() {
    int n  ;
    cin>> n ;
    
    vector<int> books(n) ;
    for(int i =0 ; i< n ; i++)
        cin >> books[i] ;

    cout<<lis(books )<<endl ;
     
    return 0;
}
