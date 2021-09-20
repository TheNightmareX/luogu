#include<bits/stdc++.h>
using namespace std;

int row_count;
vector< vector<int> > matrix;

int dp(int row, int col) {
    int value = matrix[row][col];
    if (row == row_count - 1)
        return value;
    return max(dp(row + 1, col), dp(row + 1, col + 1)) + value;
}

int main() {
    cin >> row_count;

    for (int row = 0; row < row_count; row++) {
        matrix.push_back(vector<int>());
        for (int col = 0; col <= row; col++) {
            int v;
            cin >> v;
            matrix[row].push_back(v);
        }
    }

    cout << dp(0, 0);
    
    return 0;
}