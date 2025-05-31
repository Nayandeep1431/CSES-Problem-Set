#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<ll> &arr){
    ll n = arr.size();
    map<ll, ll> mpp;
    ll left = 0, right = 0, len = 0;
    while (right < n) {
        if (mpp.find(arr[right]) != mpp.end()) {
            left = max(left, mpp[arr[right]] + 1);
        }
        mpp[arr[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }
    return len;
}

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << solve(arr) << endl;
    return 0;
}
