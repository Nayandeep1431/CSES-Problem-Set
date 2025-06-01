#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> prevSmaller(vector<ll> &arr){
    int n = arr.size() ;
    vector<ll> ans(n , 0) ;
    stack<ll> st ;
    for(int i =0 ; i< n ; i++){
        ll ele = arr[i] ;
        while(!st.empty() && arr[st.top()] >= ele)
            st.pop() ;
        
        ans[i] = (st.empty()) ? 0 : st.top() + 1 ;
        st.push(i) ;
    }
    return ans ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> arr(n) ;
    for (int i = 0; i < n; i++) {
        cin>> arr[i] ;
    }

    vector<ll> ans = prevSmaller(arr) ;
    for(auto it : ans)
        cout<< it<< " " ;
    
    return 0;
}
