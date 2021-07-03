#include <bits/stdc++.h>
using namespace std;

const int MAX_MATRIX_BORDER_LENGTH = 5000;

int main() {
    int item_count, range_border_length;
    cin >> item_count >> range_border_length;

    int matrix[MAX_MATRIX_BORDER_LENGTH + 5][MAX_MATRIX_BORDER_LENGTH + 5];

    for (int i = 1; i <= item_count; i++) {
        int row_num, col_num, value;
        cin >> row_num >> col_num >> value;
        row_num++, col_num++;
        matrix[row_num][col_num] = value;
    }

    int answer = 0;
    for (int row_num = 1; row_num <= MAX_MATRIX_BORDER_LENGTH; row_num++)
        for (int col_num = 1; col_num <= MAX_MATRIX_BORDER_LENGTH; col_num++) {
            matrix[row_num][col_num] += matrix[row_num - 1][col_num];
            matrix[row_num][col_num] += matrix[row_num][col_num - 1];
            matrix[row_num][col_num] -= matrix[row_num - 1][col_num - 1];

            bool is_range_contained = row_num >= range_border_length && col_num >= range_border_length;
            if (is_range_contained) {
                int total = matrix[row_num][col_num];
                total -= matrix[row_num - range_border_length][col_num];
                total -= matrix[row_num][col_num - range_border_length];
                total += matrix[row_num - range_border_length][col_num - range_border_length];

                answer = max(answer, total);
            }
        }

    cout << answer;
}