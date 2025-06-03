#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Check if it's safe to place a queen
bool isSafe(int row, int col, vector<vector<char>> &ch, int n) {
    int x = row, y = col;

    // Same row (left side)
    while (y >= 0) {
        if (ch[x][y] == '1')
            return false;
        y--;
    }

    x = row, y = col;
    // Upper-left diagonal
    while (x >= 0 && y >= 0) {
        if (ch[x][y] == '1')
            return false;
        x--, y--;
    }

    x = row, y = col;
    // Lower-left diagonal
    while (x < n && y >= 0) {
        if (ch[x][y] == '1')
            return false;
        x++, y--;
    }

    return true;
}

void solve(int col, vector<vector<char>> &arr, int n, ll &cnt) {
    if (col == 8) {
        cnt++;
        return;
    }
    for (int row = 0; row < n; row++) {
        if (arr[row][col] != '*' && isSafe(row, col, arr, n)) {
            arr[row][col] = '1';
            solve(col + 1, arr, n, cnt);
            arr[row][col] = '.';
        }
    }
}

ll nQueen(vector<vector<char>> &ch) {
    ll cnt = 0;
    solve(0, ch, 8, cnt);
    return cnt;
}

int main() {
    vector<vector<char>> arr(8, vector<char>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> arr[i][j];
        }
    }

    cout << nQueen(arr) << endl;
    return 0;
}
