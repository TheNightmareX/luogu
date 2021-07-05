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

    long long pos_pool = 0, neg_pool = 0;
    for (int i = 1; i < length; i++) {
        if (diffs[i] > 0)
            pos_pool += diffs[i];
        if (diffs[i] < 0)
            neg_pool += -diffs[i];
    }

    long long op_count = max(pos_pool, neg_pool);
    long long variety_count = abs(pos_pool - neg_pool) + 1;

    cout << op_count << endl << variety_count;

    return 0;
}