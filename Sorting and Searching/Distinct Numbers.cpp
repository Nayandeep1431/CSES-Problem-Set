#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    set<ll> s;
    for (int i = 0; i < n; i++) {
        ll val;
        cin >> val;
        s.insert(val);
    }
    cout << s.size() << endl;
}
