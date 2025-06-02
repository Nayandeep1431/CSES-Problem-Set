#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll findCost(const vector<ll>& arr, ll mid) {
    ll total = 0;
    for (ll x : arr) {
        total += abs(x - mid);
    }
    return total;
}

ll minCost(vector<ll>& arr) {
    ll mini = *min_element(arr.begin(), arr.end());
    ll maxi = *max_element(arr.begin(), arr.end());
    
    ll low = mini, high = maxi;
    ll ans = LLONG_MAX;

    while (low <= high) {
        ll mid = (low + high) / 2;
        ll cost1 = findCost(arr, mid);
        ll cost2 = findCost(arr, mid + 1);

        ans = min({ans, cost1, cost2});

        if (cost1 > cost2) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << minCost(arr) << '\n';
    return 0;
}
