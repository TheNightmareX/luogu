#include<bits/stdc++.h>
using namespace std;

const int MAX_COUNT = 18;

int cached_situation_counts[MAX_COUNT + 2][MAX_COUNT + 2];

int get_situation_count(int rest_number_count, int stack_number_count) {
    // only 1 situation exists when there are no more numbers can be pushed into the stack
    if (!rest_number_count)
        return 1;

    int result = cached_situation_counts[rest_number_count][stack_number_count];
    if (result) // result has already been calculated
        return result;
    result += get_situation_count(rest_number_count - 1, stack_number_count + 1); // pick into the stack
    if (stack_number_count) // requires the stack not to be empty
        result += get_situation_count(rest_number_count, stack_number_count - 1); // pop from the stack
    cached_situation_counts[rest_number_count][stack_number_count] = result;
    return result;
}

int main() {
    int number_count;
    cin >> number_count;
        
    cout << get_situation_count(number_count, 0);

    return 0;
}
