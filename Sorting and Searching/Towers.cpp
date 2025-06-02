#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    multiset<ll> towers;

    for (int i = 0; i < n; ++i) {
        ll val;
        cin >> val;
        auto it = towers.upper_bound(val); 
        if (it != towers.end()) {
            towers.erase(it);
        }
        towers.insert(val);
    }

    cout << towers.size() << "\n";
    return 0;
}
