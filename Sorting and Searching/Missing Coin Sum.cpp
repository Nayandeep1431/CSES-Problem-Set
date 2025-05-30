#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    sort(coins.begin(), coins.end());

    ll smallest_missing = 1;
    for (int i = 0; i < n; i++) {
        if (coins[i] > smallest_missing) break;
        smallest_missing += coins[i];
    }

    cout << smallest_missing << endl;
    return 0;
}
