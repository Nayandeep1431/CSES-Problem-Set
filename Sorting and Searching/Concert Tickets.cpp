#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    multiset<ll> prices;
    for (ll i = 0; i < n; i++) {
        ll val;
        cin >> val;
        prices.insert(val);
    }

    for (ll i = 0; i < m; i++) {
        ll max_price;
        cin >> max_price;

        auto it = prices.upper_bound(max_price);
        if (it == prices.begin()) {
            cout << -1 << endl;
        } else {
            --it;
            cout << *it << endl;
            prices.erase(it);
        }
    }

    return 0;
}
