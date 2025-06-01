#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0, max_time = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        max_time = max(max_time, a[i]);
    }

    cout << max(sum, 2 * max_time) << "\n";
    return 0;
}
