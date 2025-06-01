#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<ll> &arr) {
    map<ll, ll> mpp;
    ll n = arr.size();
    mpp[0] = 1;

    ll cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        ll rem = ((sum % n) + n) % n;
        cnt += mpp[rem];
        mpp[rem]++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << solve(arr) << "\n";
    return 0;
}
