#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) cin >> w[i];

    sort(w.begin(), w.end());
    int i = 0, j = n - 1, gondolas = 0;

    while (i <= j) {
        if (w[i] + w[j] <= x) {
            i++;
        }
        j--;
        gondolas++;
    }

    cout << gondolas << endl;
    return 0;
}
