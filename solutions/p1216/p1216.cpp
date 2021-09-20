#include<bits/stdc++.h>
using namespace std;

int row_count;
vector< vector< pair<int, int> > > matrix;

int dp(int row, int col) {
    if (row == row_count - 1)
        return matrix[row][col].first;

    int ret = matrix[row][col].second != -1
      ? matrix[row][col].second
      : max(dp(row + 1, col), dp(row + 1, col + 1)) + matrix[row][col].first;

    matrix[row][col].second = ret;

    return ret;
}

int main() {
    cin >> row_count;

    for (int row = 0; row < row_count; row++) {
        matrix.push_back(vector< pair<int, int> >());
        for (int col = 0; col <= row; col++) {
            int v;
            cin >> v;
            matrix[row].push_back(make_pair(v, -1));
        }
    }

    cout << dp(0, 0);
    
    return 0;
}