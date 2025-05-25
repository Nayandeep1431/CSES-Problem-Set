#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &temp, int n) {
    int ans = 0;
    for (int i = 0; i < temp.size(); i++)
        ans ^= temp[i];

    for (int i = 1; i <= n; i++) {
        ans ^= i;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> temp;
    for (int i = 0; i < n - 1; i++) {
        int val;
        cin >> val;
        temp.push_back(val);
    }
    cout << solve(temp, n);
}
