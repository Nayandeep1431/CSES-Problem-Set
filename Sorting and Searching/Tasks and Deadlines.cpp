#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }

    sort(arr.begin(), arr.end(), cmp);

    ll reward = 0;
    ll finishTime = 0;

    for (int i = 0; i < n; i++) {
        ll duration = arr[i].first;
        ll deadline = arr[i].second;

        finishTime += duration;
        reward += (deadline - finishTime);
    }

    cout << reward << '\n';
    return 0;
}
