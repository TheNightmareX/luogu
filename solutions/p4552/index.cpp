#include<bits/stdc++.h>
using namespace std;

int const MAX_LENGTH = 100000;

int main() {
    int length;
    cin >> length;

    int values[MAX_LENGTH + 5], diffs[MAX_LENGTH + 5];
    for (int i = 0; i < length; i++) {
        cin >> values[i];
        
        if (i)
            diffs[i] = values[i] - values[i - 1];
        else
            diffs[i] = values[i];
    }

    int op_count = 0, variety_count = 1;
    while (true) {
        const int NOT_FOUND = -1;

        int pos_i = NOT_FOUND, neg_i = NOT_FOUND;
        for (int i = 0; i < length; i++) {
            if (pos_i != NOT_FOUND && neg_i != NOT_FOUND)
                break;
            if (pos_i == NOT_FOUND && diffs[i] > 0)
                pos_i = i;
            if (neg_i == NOT_FOUND && diffs[i] < 0)
                neg_i = i;
        }

        if (pos_i != NOT_FOUND && neg_i != NOT_FOUND) {
            int gap = min(diffs[pos_i], abs(diffs[neg_i]));
            op_count += gap;
            diffs[pos_i] -= gap;
            diffs[neg_i] += gap;
        } else if (pos_i == NOT_FOUND && neg_i == NOT_FOUND) {
            break;
        } else if (pos_i == NOT_FOUND) {
            int gap = abs(diffs[neg_i]);
            op_count += gap;
            variety_count += gap;
            break;
        } else if (neg_i == NOT_FOUND) {
            int gap = diffs[pos_i];
            op_count += gap;
            variety_count += gap;
            break;
        } else {
            "just prefer `else if`";
        }
    }

    cout << op_count << endl << variety_count;

    return 0;
}