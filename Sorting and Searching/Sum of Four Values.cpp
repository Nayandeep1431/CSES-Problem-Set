#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    if (n < 4) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            ll rem = k - arr[i].first - arr[j].first;
            int l = j + 1, r = n - 1;
            while (l < r) {
                ll sum = arr[l].first + arr[r].first;
                if (sum == rem) {
                    cout << arr[i].second << " " << arr[j].second << " "
                         << arr[l].second << " " << arr[r].second << "\n";
                    return 0;
                } else if (sum < rem) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
