#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(ll n, ll val) {
    ll num = n;
    set<ll> st;
    while (val != 0 && n > 0) {
        if (n <= val) {
            val -= n;
            st.insert(n);
        }
        n--;
    }

    cout << "YES" << endl;

    cout << st.size() << endl;
    for (auto &it : st) {
        cout << it << " ";
    }
    cout << endl;

    cout << num - st.size() << endl;
    for (ll i = 1; i <= num; i++) {
        if (st.find(i) == st.end())
            cout << i << " ";
    }
    cout << endl;
}

int main() {
    ll n;
    cin >> n;

    ll sum = n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    } else {
        ll val = sum / 2;
        solve(n, val);
    }
}
