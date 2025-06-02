#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int SIZE = 1e6 + 1;
vector<int> divi(SIZE, 0);
int maxi = 1;

void divisor(int n) {
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divi[i]++;
            if (divi[i] > 1)
                maxi = max(maxi, i);
            int d = n / i;
            if (d != i) {
                divi[d]++;
                if (divi[d] > 1)
                    maxi = max(maxi, d);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        divisor(n);
    }

    cout << maxi << '\n';
    return 0;
}
