#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<pair<ll , ll>> arr(n);
    for (int i = 0; i < n; i++){
    	cin>> arr[i].first ;
    	arr[i].second = i + 1 ;
	} 
	
	sort(arr.begin() , arr.end()) ;
	int cnt = 1;
	int temp = -1 ;
	for(int i =0 ; i< n ; i++){
		if(arr[i].second < temp )
			cnt++ ;
		
		temp = arr[i].second ;	
	}
    
    cout << cnt<<endl ;
    return 0;
}
