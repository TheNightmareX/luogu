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
    int pool = 0;

    for (int i = 1; i < length; i++) {
        if (pool > 0 && diffs[i] > 0 || pool < 0 && diffs[i] < 0) {
            pool += diffs[i];
        } else {
            op_count += abs(pool) < abs(diffs[i]) ? abs(pool) : abs(diffs[i]);
            pool += diffs[i];
        }
    }

    op_count += abs(pool);
    diffs[0] += pool;
    variety_count += abs(pool);

    cout << op_count << endl << variety_count;

    return 0;
}