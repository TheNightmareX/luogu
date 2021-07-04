#include<bits/stdc++.h>
using namespace std;

int main() {
    int value_count, max_range_length;
    cin >> value_count >> max_range_length;

    const int MAX_VALUE_COUNT = 500000;
    int values[MAX_VALUE_COUNT + 5], sumed_values[MAX_VALUE_COUNT + 5];
    int left_sum_indexes[MAX_VALUE_COUNT], useful_left_sum_indexes_start = 0, useful_left_sum_indexes_end = 0; // 含左不含右
    int answer = -0x3f3f3f3f; // -infinity
    for (int i = 1; i <= value_count; i++) {
        cin >> values[i];
        sumed_values[i] = sumed_values[i - 1] + values[i];

        int new_end = useful_left_sum_indexes_end;
        for (int ii = useful_left_sum_indexes_start; ii < useful_left_sum_indexes_end; ii++) {
            if (left_sum_indexes[ii] + max_range_length < i)
                useful_left_sum_indexes_start++;
            if (sumed_values[left_sum_indexes[ii]] >= sumed_values[i])
                new_end--;
        }
        useful_left_sum_indexes_end = new_end;

        if (useful_left_sum_indexes_end) {
            int min_left_sum = sumed_values[left_sum_indexes[useful_left_sum_indexes_start]];
            int cur_right_sum = sumed_values[i];
            answer = max(answer, cur_right_sum - min_left_sum);
        }

        left_sum_indexes[useful_left_sum_indexes_end++] = i;

        // for (int ii = useful_left_sum_indexes_start; ii < useful_left_sum_indexes_end; ii++)
        //     cout << sumed_values[left_sum_indexes[ii]] << ' ';
        // cout << endl;
    }

    cout << answer;

    return 0;
}
